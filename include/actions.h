/*
  cxNES - NES/Famicom Emulator
  Copyright (C) 2011-2016 Ryan Jackson

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

#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#define ACTION_DEFERRED_FLAG               0x80000000
#define ACTION_ALLOWED_MASK                0x70000000
#define ACTION_ALLOWED_WHILE_PAUSED        0x20000000
#define ACTION_ALLOWED_WHILE_STOPPED       0x10000000
#define ACTION_TYPE_MASK                   0x0f000000
#define ACTION_PREFIX_MASK                 0x00ff0000
#define ACTION_TYPE_DIGITAL                0x00000000
#define ACTION_TYPE_ANALOG                 0x01000000
#define ACTION_TYPE_MOUSE                  0x02000000

#define ACTION_NONE ~0

#define ACTION_CONTROLLER_1_A         1
#define ACTION_CONTROLLER_1_B         2
#define ACTION_CONTROLLER_1_SELECT    4
#define ACTION_CONTROLLER_1_START     8
#define ACTION_CONTROLLER_1_UP       16
#define ACTION_CONTROLLER_1_DOWN     32
#define ACTION_CONTROLLER_1_LEFT     64
#define ACTION_CONTROLLER_1_RIGHT   128
#define ACTION_CONTROLLER_1_SNES_A  256
#define ACTION_CONTROLLER_1_SNES_X  512
#define ACTION_CONTROLLER_1_SNES_L  1024
#define ACTION_CONTROLLER_1_SNES_R  2048
#define ACTION_CONTROLLER_2_A         (1 | 0x1000)
#define ACTION_CONTROLLER_2_B         (2 | 0x1000)
#define ACTION_CONTROLLER_2_SELECT    (4 | 0x1000)
#define ACTION_CONTROLLER_2_START     (8 | 0x1000)
#define ACTION_CONTROLLER_2_UP       (16 | 0x1000)
#define ACTION_CONTROLLER_2_DOWN     (32 | 0x1000)
#define ACTION_CONTROLLER_2_LEFT     (64 | 0x1000)
#define ACTION_CONTROLLER_2_RIGHT   (128 | 0x1000)
#define ACTION_CONTROLLER_2_SNES_A  (256 | 0x1000)
#define ACTION_CONTROLLER_2_SNES_X  (512 | 0x1000)
#define ACTION_CONTROLLER_2_SNES_L  (1024| 0x1000)
#define ACTION_CONTROLLER_2_SNES_R  (2048| 0x1000)
#define ACTION_CONTROLLER_3_A         (1 | 0x2000)
#define ACTION_CONTROLLER_3_B         (2 | 0x2000)
#define ACTION_CONTROLLER_3_SELECT    (4 | 0x2000)
#define ACTION_CONTROLLER_3_START     (8 | 0x2000)
#define ACTION_CONTROLLER_3_UP       (16 | 0x2000)
#define ACTION_CONTROLLER_3_DOWN     (32 | 0x2000)
#define ACTION_CONTROLLER_3_LEFT     (64 | 0x2000)
#define ACTION_CONTROLLER_3_RIGHT   (128 | 0x2000)
#define ACTION_CONTROLLER_3_SNES_A  (256 | 0x2000)
#define ACTION_CONTROLLER_3_SNES_X  (512 | 0x2000)
#define ACTION_CONTROLLER_3_SNES_L  (1024| 0x2000)
#define ACTION_CONTROLLER_3_SNES_R  (2048| 0x2000)
#define ACTION_CONTROLLER_4_A         (1 | 0x3000)
#define ACTION_CONTROLLER_4_B         (2 | 0x3000)
#define ACTION_CONTROLLER_4_SELECT    (4 | 0x3000)
#define ACTION_CONTROLLER_4_START     (8 | 0x3000)
#define ACTION_CONTROLLER_4_UP       (16 | 0x3000)
#define ACTION_CONTROLLER_4_DOWN     (32 | 0x3000)
#define ACTION_CONTROLLER_4_LEFT     (64 | 0x3000)
#define ACTION_CONTROLLER_4_RIGHT   (128 | 0x3000)
#define ACTION_CONTROLLER_4_SNES_A  (256 | 0x3000)
#define ACTION_CONTROLLER_4_SNES_X  (512 | 0x3000)
#define ACTION_CONTROLLER_4_SNES_L  (1024| 0x3000)
#define ACTION_CONTROLLER_4_SNES_R  (2048| 0x3000)
#define ACTION_CONTROLLER_TURBO_FLAG 0x4000
#define ACTION_CONTROLLER_TURBO_TOGGLE_FLAG 0x8000

#define ACTION_CONTROLLER_1_A_TURBO				\
	(ACTION_CONTROLLER_1_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_1_B_TURBO \
	(ACTION_CONTROLLER_1_B | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_B_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_B | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_1_SNES_A_TURBO \
	(ACTION_CONTROLLER_1_SNES_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_SNES_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_SNES_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_1_SNES_X_TURBO \
	(ACTION_CONTROLLER_1_SNES_X | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_SNES_X_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_SNES_X | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_1_SNES_L_TURBO \
	(ACTION_CONTROLLER_1_SNES_L | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_SNES_L_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_SNES_L | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_1_SNES_R_TURBO \
	(ACTION_CONTROLLER_1_SNES_R | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_1_SNES_R_TURBO_TOGGLE \
	(ACTION_CONTROLLER_1_SNES_R | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)

#define ACTION_CONTROLLER_2_A_TURBO				\
	(ACTION_CONTROLLER_2_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_2_B_TURBO \
	(ACTION_CONTROLLER_2_B | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_B_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_B | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_2_SNES_A_TURBO \
	(ACTION_CONTROLLER_2_SNES_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_SNES_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_SNES_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_2_SNES_X_TURBO \
	(ACTION_CONTROLLER_2_SNES_X | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_SNES_X_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_SNES_X | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_2_SNES_L_TURBO \
	(ACTION_CONTROLLER_2_SNES_L | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_SNES_L_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_SNES_L | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_2_SNES_R_TURBO \
	(ACTION_CONTROLLER_2_SNES_R | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_2_SNES_R_TURBO_TOGGLE \
	(ACTION_CONTROLLER_2_SNES_R | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)

#define ACTION_CONTROLLER_3_A_TURBO				\
	(ACTION_CONTROLLER_3_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_3_B_TURBO \
	(ACTION_CONTROLLER_3_B | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_B_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_B | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_3_SNES_A_TURBO \
	(ACTION_CONTROLLER_3_SNES_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_SNES_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_SNES_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_3_SNES_X_TURBO \
	(ACTION_CONTROLLER_3_SNES_X | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_SNES_X_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_SNES_X | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_3_SNES_L_TURBO \
	(ACTION_CONTROLLER_3_SNES_L | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_SNES_L_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_SNES_L | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_3_SNES_R_TURBO \
	(ACTION_CONTROLLER_3_SNES_R | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_3_SNES_R_TURBO_TOGGLE \
	(ACTION_CONTROLLER_3_SNES_R | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)

#define ACTION_CONTROLLER_4_A_TURBO				\
	(ACTION_CONTROLLER_4_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_4_B_TURBO \
	(ACTION_CONTROLLER_4_B | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_B_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_B | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_4_SNES_A_TURBO \
	(ACTION_CONTROLLER_4_SNES_A | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_SNES_A_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_SNES_A | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_4_SNES_X_TURBO \
	(ACTION_CONTROLLER_4_SNES_X | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_SNES_X_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_SNES_X | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_4_SNES_L_TURBO \
	(ACTION_CONTROLLER_4_SNES_L | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_SNES_L_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_SNES_L | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)
#define ACTION_CONTROLLER_4_SNES_R_TURBO \
	(ACTION_CONTROLLER_4_SNES_R | ACTION_CONTROLLER_TURBO_FLAG)
#define ACTION_CONTROLLER_4_SNES_R_TURBO_TOGGLE \
	(ACTION_CONTROLLER_4_SNES_R | ACTION_CONTROLLER_TURBO_TOGGLE_FLAG)

#define ACTION_KEYBOARD_F8            0x00010002
#define ACTION_KEYBOARD_ENTER         0x00010004
#define ACTION_KEYBOARD_LEFTBRACKET   0x00010008
#define ACTION_KEYBOARD_RIGHTBRACKET  0x00010010
#define ACTION_KEYBOARD_KANA          0x00010102
#define ACTION_KEYBOARD_RSHIFT        0x00010104
#define ACTION_KEYBOARD_YEN           0x00010108
#define ACTION_KEYBOARD_STOP          0x00010110
#define ACTION_KEYBOARD_F7            0x00010202
#define ACTION_KEYBOARD_AT            0x00010204
#define ACTION_KEYBOARD_COLON         0x00010208
#define ACTION_KEYBOARD_SEMICOLON     0x00010210
#define ACTION_KEYBOARD_UNDERSCORE    0x00010302
#define ACTION_KEYBOARD_SLASH         0x00010304
#define ACTION_KEYBOARD_MINUS         0x00010308
#define ACTION_KEYBOARD_CARET         0x00010310
#define ACTION_KEYBOARD_F6            0x00010402
#define ACTION_KEYBOARD_o             0x00010404
#define ACTION_KEYBOARD_l             0x00010408
#define ACTION_KEYBOARD_k             0x00010410
#define ACTION_KEYBOARD_PERIOD        0x00010502
#define ACTION_KEYBOARD_COMMA         0x00010504
#define ACTION_KEYBOARD_p             0x00010508
#define ACTION_KEYBOARD_0             0x00010510
#define ACTION_KEYBOARD_F5            0x00010602
#define ACTION_KEYBOARD_i             0x00010604
#define ACTION_KEYBOARD_u             0x00010608
#define ACTION_KEYBOARD_j             0x00010610
#define ACTION_KEYBOARD_m             0x00010702
#define ACTION_KEYBOARD_n             0x00010704
#define ACTION_KEYBOARD_9             0x00010708
#define ACTION_KEYBOARD_8             0x00010710
#define ACTION_KEYBOARD_F4            0x00010802
#define ACTION_KEYBOARD_y             0x00010804
#define ACTION_KEYBOARD_g             0x00010808
#define ACTION_KEYBOARD_h             0x00010810
#define ACTION_KEYBOARD_b             0x00010902
#define ACTION_KEYBOARD_v             0x00010904
#define ACTION_KEYBOARD_7             0x00010908
#define ACTION_KEYBOARD_6             0x00010910
#define ACTION_KEYBOARD_F3            0x00010a02
#define ACTION_KEYBOARD_t             0x00010a04
#define ACTION_KEYBOARD_r             0x00010a08
#define ACTION_KEYBOARD_d             0x00010a10
#define ACTION_KEYBOARD_f             0x00010b02
#define ACTION_KEYBOARD_c             0x00010b04
#define ACTION_KEYBOARD_5             0x00010b08
#define ACTION_KEYBOARD_4             0x00010b10
#define ACTION_KEYBOARD_F2            0x00010c02
#define ACTION_KEYBOARD_w             0x00010c04
#define ACTION_KEYBOARD_s             0x00010c08
#define ACTION_KEYBOARD_a             0x00010c10
#define ACTION_KEYBOARD_x             0x00010d02
#define ACTION_KEYBOARD_z             0x00010d04
#define ACTION_KEYBOARD_e             0x00010d08
#define ACTION_KEYBOARD_3             0x00010d10
#define ACTION_KEYBOARD_F1            0x00010e02
#define ACTION_KEYBOARD_ESCAPE        0x00010e04
#define ACTION_KEYBOARD_q             0x00010e08
#define ACTION_KEYBOARD_LCTRL         0x00010e10
#define ACTION_KEYBOARD_LSHIFT        0x00010f02
#define ACTION_KEYBOARD_GRAPH         0x00010f04
#define ACTION_KEYBOARD_1             0x00010f08
#define ACTION_KEYBOARD_2             0x00010f10
#define ACTION_KEYBOARD_HOME          0x00011002
#define ACTION_KEYBOARD_UP            0x00011004
#define ACTION_KEYBOARD_RIGHT         0x00011008
#define ACTION_KEYBOARD_LEFT          0x00011010
#define ACTION_KEYBOARD_DOWN          0x00011102
#define ACTION_KEYBOARD_SPACE         0x00011104
#define ACTION_KEYBOARD_DEL           0x00011108
#define ACTION_KEYBOARD_INS           0x00011110
#define ACTION_KEYBOARD_BS            0x0001f000
#define ACTION_KEYBOARD_TAB           0x0001f001
#define ACTION_KEYBOARD_CAPS          0x0001f002
#define ACTION_KEYBOARD_PGUP          0x0001f004
#define ACTION_KEYBOARD_PGDN          0x0001f005
#define ACTION_KEYBOARD_END           0x0001f006
#define ACTION_KEYBOARD_BACKQUOTE     0x0001f008
#define ACTION_KEYBOARD_APOSTROPHE    0x0001f009
#define ACTION_KEYBOARD_EQUALS        0x0001f00a
#define ACTION_KEYBOARD_PAUSE         0x0001f00b
#define ACTION_KEYBOARD_BREAK         0x0001f00c
#define ACTION_KEYBOARD_RESET         0x0001f00d
#define ACTION_KEYBOARD_NUMLOCK       0x0001f00e
#define ACTION_KEYBOARD_LALT          0x0001f00f
#define ACTION_KEYBOARD_RALT          0x0001f010
#define ACTION_KEYBOARD_F9            0x0001f011
#define ACTION_KEYBOARD_F10           0x0001f012
#define ACTION_KEYBOARD_F11           0x0001f013
#define ACTION_KEYBOARD_F12           0x0001f014
#define ACTION_KEYBOARD_BACKSLASH     0x0001f015
#define ACTION_KEYBOARD_RCTRL         0x0001f016

#define ACTION_MAT_2_1  0x00020001
#define ACTION_MAT_2_2  0x00020002
#define ACTION_MAT_2_3  0x00020003
#define ACTION_MAT_2_4  0x00020004
#define ACTION_MAT_2_5  0x00020005
#define ACTION_MAT_2_6  0x00020006
#define ACTION_MAT_2_7  0x00020007
#define ACTION_MAT_2_8  0x00020008
#define ACTION_MAT_2_9  0x00020009
#define ACTION_MAT_2_10 0x0002000A
#define ACTION_MAT_2_11 0x0002000B
#define ACTION_MAT_2_12 0x0002000C

#define ACTION_MAT_1_1  0x00030001
#define ACTION_MAT_1_2  0x00030002
#define ACTION_MAT_1_3  0x00030003
#define ACTION_MAT_1_4  0x00030004
#define ACTION_MAT_1_5  0x00030005
#define ACTION_MAT_1_6  0x00030006
#define ACTION_MAT_1_7  0x00030007
#define ACTION_MAT_1_8  0x00030008
#define ACTION_MAT_1_9  0x00030009
#define ACTION_MAT_1_10 0x0003000A
#define ACTION_MAT_1_11 0x0003000B
#define ACTION_MAT_1_12 0x0003000C

#define ACTION_ZAPPER_1_UPDATE_LOCATION    0x02040001
#define ACTION_ZAPPER_2_UPDATE_LOCATION    0x02040011
#define ACTION_ZAPPER_1_TRIGGER            0x00040002
#define ACTION_ZAPPER_1_TRIGGER_OFFSCREEN  0x00040004
#define ACTION_ZAPPER_2_TRIGGER            0x00040012
#define ACTION_ZAPPER_2_TRIGGER_OFFSCREEN  0x00040014

#define ACTION_ARKANOID_1_DIAL          0x01050001
#define ACTION_ARKANOID_1_DIAL_MOUSE    0x02050002
#define ACTION_ARKANOID_1               0x00050004
#define ACTION_ARKANOID_2_DIAL          0x01050011
#define ACTION_ARKANOID_2_DIAL_MOUSE    0x02050012
#define ACTION_ARKANOID_2               0x00050014

#define ACTION_MOUSE_1_UPDATE_LOCATION  0x02060001
#define ACTION_MOUSE_2_UPDATE_LOCATION  0x02060011
#define ACTION_MOUSE_3_UPDATE_LOCATION  0x02060021
#define ACTION_MOUSE_4_UPDATE_LOCATION  0x02060031
#define ACTION_MOUSE_1_LEFTBUTTON       0x00060002
#define ACTION_MOUSE_1_RIGHTBUTTON      0x00060004
#define ACTION_MOUSE_2_LEFTBUTTON       0x00060012
#define ACTION_MOUSE_2_RIGHTBUTTON      0x00060014
#define ACTION_MOUSE_3_LEFTBUTTON       0x00060022
#define ACTION_MOUSE_3_RIGHTBUTTON      0x00060024
#define ACTION_MOUSE_4_LEFTBUTTON       0x00060032
#define ACTION_MOUSE_4_RIGHTBUTTON      0x00060034

#define ACTION_HARD_RESET           0x00ffff01
#define ACTION_SOFT_RESET           0x00ffff02
#define ACTION_VS_COIN_SWITCH_1     0x00ffff03
#define ACTION_VS_COIN_SWITCH_2     0x00ffff04
#define ACTION_VS_SERVICE_SWITCH    0x00ffff05
#define ACTION_DIP_SWITCH_1         0x20ffff06
#define ACTION_DIP_SWITCH_2         0x20ffff07
#define ACTION_DIP_SWITCH_3         0x20ffff08
#define ACTION_DIP_SWITCH_4         0x20ffff09
#define ACTION_DIP_SWITCH_5         0x20ffff0a
#define ACTION_DIP_SWITCH_6         0x20ffff0b
#define ACTION_DIP_SWITCH_7         0x20ffff0c
#define ACTION_DIP_SWITCH_8         0x20ffff0d
#define ACTION_QUIT                 0x30ffff0e
#define ACTION_FDS_EJECT            0x00ffff0f
#define ACTION_FDS_SELECT           0x00ffff10
#define ACTION_KEYBOARD_ENABLE      0x20ffff11
#define ACTION_TOGGLE_SPRITE_LIMIT  0x20ffff14
#define ACTION_TOGGLE_SPRITES       0x00ffff15
#define ACTION_TOGGLE_BG            0x00ffff16
#define ACTION_TOGGLE_SCANLINE_RENDERER            0x00ffff17
#define ACTION_TOGGLE_CHEATS        0x20ffff18
#define ACTION_SWITCH_FOUR_PLAYER_MODE 0x20ffff19
#define ACTION_MICROPHONE            0x00ffff1a

#define ACTION_TOGGLE_MOUSE_GRAB    0x20ffff1e
#define ACTION_TOGGLE_FPS           0x30ffff1f

#define ACTION_DEVICE_SELECT_PORT1  0x20ffff20
#define ACTION_DEVICE_SELECT_PORT2  0x20ffff21
#define ACTION_DEVICE_SELECT_PORT3  0x20ffff22
#define ACTION_DEVICE_SELECT_PORT4  0x20ffff23
#define ACTION_DEVICE_SELECT_EXP    0x20ffff24
#define ACTION_DEVICE_CONNECT_PORT1 0x20ffff25
#define ACTION_DEVICE_CONNECT_PORT2 0x20ffff26
#define ACTION_DEVICE_CONNECT_PORT3 0x20ffff27
#define ACTION_DEVICE_CONNECT_PORT4 0x20ffff28
#define ACTION_DEVICE_CONNECT_EXP   0x20ffff29
#define ACTION_PAUSE                0xa0ffff2a
#define ACTION_TOGGLE_MENUBAR       0x30ffff2b
#define ACTION_TOGGLE_CPU_TRACE     0x20ffff2c

#define ACTION_STATE_LOAD_0 0xa0ffff2d
#define ACTION_STATE_LOAD_1 0xa0ffff2e
#define ACTION_STATE_LOAD_2 0xa0ffff2f
#define ACTION_STATE_LOAD_3 0xa0ffff30
#define ACTION_STATE_LOAD_4 0xa0ffff31
#define ACTION_STATE_LOAD_5 0xa0ffff32
#define ACTION_STATE_LOAD_6 0xa0ffff33
#define ACTION_STATE_LOAD_7 0xa0ffff34
#define ACTION_STATE_LOAD_8 0xa0ffff35
#define ACTION_STATE_LOAD_9 0xa0ffff36
#define ACTION_STATE_LOAD_NEWEST 0xa0ffff37
#define ACTION_STATE_SAVE_0 0xa0ffff38
#define ACTION_STATE_SAVE_1 0xa0ffff39
#define ACTION_STATE_SAVE_2 0xa0ffff3a
#define ACTION_STATE_SAVE_3 0xa0ffff3b
#define ACTION_STATE_SAVE_4 0xa0ffff3c
#define ACTION_STATE_SAVE_5 0xa0ffff3d
#define ACTION_STATE_SAVE_6 0xa0ffff3e
#define ACTION_STATE_SAVE_7 0xa0ffff3f
#define ACTION_STATE_SAVE_8 0xa0ffff40
#define ACTION_STATE_SAVE_9 0xa0ffff41
#define ACTION_STATE_SAVE_OLDEST 0xa0ffff42
#define ACTION_STATE_SELECT_1 0x20ffff43
#define ACTION_STATE_SELECT_2 0x20ffff44
#define ACTION_STATE_SELECT_3 0x20ffff45
#define ACTION_STATE_SELECT_4 0x20ffff46
#define ACTION_STATE_SELECT_5 0x20ffff47
#define ACTION_STATE_SELECT_6 0x20ffff48
#define ACTION_STATE_SELECT_7 0x20ffff49
#define ACTION_STATE_SELECT_8 0x20ffff4a
#define ACTION_STATE_SELECT_9 0x20ffff4b
#define ACTION_STATE_SELECT_0 0x20ffff4c
#define ACTION_STATE_SAVE_SELECTED 0xa0ffff4d
#define ACTION_STATE_LOAD_SELECTED 0xa0ffff4e
#define ACTION_STATE_SELECT_PREV 0x20ffff4f
#define ACTION_STATE_SELECT_NEXT 0x20ffff50

#define ACTION_SAVE_SCREENSHOT      0x20ffff51
#define ACTION_SYSTEM_TYPE_SELECT   0x00ffff52

#define ACTION_ALT_SPEED            0x20ffff53

#define ACTION_TOGGLE_FULLSCREEN       0x30ffff54
#define ACTION_OVERCLOCK_DEFAULT       0x80ffff55
#define ACTION_OVERCLOCK_DISABLED      0x80ffff56
#define ACTION_OVERCLOCK_POST_RENDER   0x80ffff57
#define ACTION_OVERCLOCK_VBLANK        0x80ffff58

#endif
