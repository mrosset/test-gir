#!/usr/bin/env gjs

const System = imports.system;
const console = imports.console;

const Clutter = imports.gi.Clutter;
const GLib = imports.gi.GLib;
const GIR  = imports.gi.GIRepository;
const GObject  = imports.gi.GObject;

imports.gi.versions.Gtk = '3.0';
imports.gi.versions.WebKit2 = '4.0';

const Gtk = imports.gi.Gtk;
const WebKit = imports.gi.WebKit2;


let repo = GIR.Repository.get_default();

let info = repo.find_by_name("Clutter", "PaintNode");
let type = GIR.registered_type_info_get_g_type(info);

log(GObject.type_name(type));

Gtk.init(null);

let win = new Gtk.Window();

let view = new WebKit.WebView();
view.load_uri('http://www.google.com/');
win.add(view);

win.connect('destroy', () => {
    Gtk.main_quit();
});

win.set_size_request(640, 480);
win.show_all();

Gtk.main();
