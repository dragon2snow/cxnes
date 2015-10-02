---
title: cxNES Download
layout: default
---

{% for release in site.github.releases %}
  {% if release.draft %}
    {% continue %}
  {% endif %}
## [{{ release.name }}]({{ release.html_url }})  

  {{ release.body }}

{% for asset in release.assets %}
    [{{ asset.label | default: asset.name }}]({{ asset.browser_download_url }}) {{ asset.size }}  
{% endfor %}
  [Source code (.zip)]({{ release.zipball_url }})  
  [Source code (.tar.gz)]({{ release.tarball_url }})
{% endfor %}


