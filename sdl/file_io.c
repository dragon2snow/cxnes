/*
  cxNES - NES/Famicom Emulator
  Copyright (C) 2011-2015 Ryan Jackson

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation.; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <stdio.h>
#include <string.h>

#if _WIN32
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#include "SDL.h"
#include "log.h"

int check_file_exists(const char *name)
{
	SDL_RWops *file;

	file = SDL_RWFromFile(name, "rb");
	if (!file) {
		return 0;
	}

	file->close(file);

	return 1;
}

size_t get_file_size(const char *name)
{
	SDL_RWops *file;
	int size;

	file = SDL_RWFromFile(name, "rb");
	if (!file) {
		err_message("%s", SDL_GetError());
		return -1;
	}

	size = SDL_RWsize(file);
	
	file->close(file);

	return size;
}

/* Load file "name" into buffer "buf" of size "size" */
int readfile(const char *name, uint8_t *buf, uint32_t size)
{
	SDL_RWops *file;

	file = SDL_RWFromFile(name, "rb");
	if (!file) {
		err_message("%s", SDL_GetError());
		return -1;
	}

	if (SDL_RWsize(file) == 0) {
		file->close(file);
		return 0;
	}

	if (file->read(file, buf, size, 1) < 1) {
		err_message("%s", SDL_GetError());
		file->close(file);
		return 1;
	}

	file->close(file);

	return 0;
}

/* write file "name" from buffer "buf" of size "size" */
int writefile(const char *name, uint8_t *buf, uint32_t size)
{
	SDL_RWops *file;

	file = SDL_RWFromFile(name, "wb");
	if (!file) {
		err_message("%s", SDL_GetError());
		return -1;
	}

	if (file->write(file, buf, size, 1) < 1) {
		err_message("%s", SDL_GetError());
		file->close(file);
		return 1;
	}

	file->close(file);

	return 0;
}

int process_file(const char *filename, void *data,
		 void (*callback)(char *, int, void *),
		 int trim_leading_ws, int trim_trailing_ws)
{
	char *buffer;
	char *line;
	int size;
	int num;

	size = get_file_size(filename);
	if ((int)size < 0)
		return -1;

	buffer = malloc(size + 1);
	if (!buffer)
		return -1;

	if (readfile(filename, (uint8_t *)buffer, size) < 0) {
		free(buffer);
		return -1;
	}

	line = buffer;
	num = 0;
	while (line < buffer + size) {
		char *end, *p;
		int len;

		num++;
		end = strchr(line, '\n');
		if (!end)
			end = buffer + size;

		*end = '\0';
		end++;
		len = end - line - 1;

		p = line;
		if (trim_leading_ws) {
			while (*p && isspace(*p)) {
				p++;
				len--;
			}
		}

		if (trim_trailing_ws) {
			while (len > 0 && isspace(p[len - 1])) {
				p[len - 1] = '\0';
				len--;
			}
		}

		if ((len == 0) || (*p == '#')) {
			line = end;
			continue;
		}

		callback(p, num, data);

		line = end;
	}

	free(buffer);
	return 0;
}

#if _WIN32
#define WIN_TICKS_PER_SEC 10000000 
#define WIN_SECS_BEFORE_UNIX_EPOCH 11644473600LL

int get_file_mtime(const char *path, int64_t *secptr, int32_t *nsecptr)
{
	FILETIME mtime;
	HANDLE fh;
	int64_t sec;
	int32_t nsec;
	uint64_t tmp;
	int rc;

	fh = CreateFileA(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0,
	                 NULL);

	if (fh == INVALID_HANDLE_VALUE)
		return -1;

	rc = GetFileTime(fh, NULL, NULL, &mtime);

	CloseHandle(fh);

	if (!rc)
		return -1;

	tmp = mtime.dwLowDateTime;
	tmp <<= 32;
	tmp |= mtime.dwHighDateTime;

	sec = tmp / WIN_TICKS_PER_SEC;
	sec -= WIN_SECS_BEFORE_UNIX_EPOCH;

	nsec = (tmp % WIN_TICKS_PER_SEC);

	if (nsec && (sec < 0)) {
		sec++;
		nsec -= WIN_TICKS_PER_SEC;
	}

	nsec *= 100;

	if (secptr)
		*secptr = sec;

	if (nsecptr)
		*nsecptr = nsec;

	return 0;
}
#else
int get_file_mtime(const char *path, int64_t *secptr, int32_t *nsecptr)
{
	struct stat stat;
	int rc;

	rc = lstat(path, &stat);
	if (rc < 0)
		return -1;

	if (secptr)
		*secptr = stat.st_mtim.tv_sec;

	if (nsecptr)
		*nsecptr = stat.st_mtim.tv_nsec;

	return 0;
}
#endif

