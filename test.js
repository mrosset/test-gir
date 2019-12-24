#!/usr/bin/env gjs

const System = imports.system;
const console = imports.console;

const Clutter = imports.gi.Clutter;
const GLib = imports.gi.GLib;
const GIR  = imports.gi.GIRepository;
const GObject  = imports.gi.GObject;

let repo = GIR.Repository.get_default();

let info = repo.find_by_name("Clutter", "PaintNode");
let type = GIR.registered_type_info_get_g_type(info);

log(GObject.type_name(type));
