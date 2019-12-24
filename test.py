#!/usr/bin/env python

import gi

gi.require_version("GIRepository", "2.0")
gi.require_version("Clutter", "1.0")

from gi.repository import GIRepository
from gi.repository import Clutter
from gi.repository import GObject

repo = GIRepository.Repository().get_default()


info = repo.find_by_name("Clutter", "PaintNode")
type = GIRepository.registered_type_info_get_g_type(info)

print(GObject.type_name(type))
