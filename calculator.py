#!/usr/bin/env python3
#percentage_calculator.py
import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk
from src.config import *
from src.logic import *

def on_activate(program):
    window = Gtk.ApplicationWindow(application=program)
    grid = Gtk.Grid()
    scrolled_window = Gtk.ScrolledWindow()
    input = Gtk.Entry()
    output = Gtk.TextView()

    configure(window, grid, scrolled_window, input, output)
    connect_signals(window, input, output)
    input.grab_focus() 
    window.present()

program = Gtk.Application()
program.connect("activate", on_activate)
program.run(None)
