#src/logic.py
import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk
import os
import ctypes

script_dir = os.path.dirname(os.path.realpath(__file__))
lib_path = os.path.join(script_dir, '..', 'lib', 'libtinyexpr.so')

tinyexpr = ctypes.CDLL(lib_path)
tinyexpr.te_interp.restype = ctypes.c_double
tinyexpr.te_interp.argtypes = [ctypes.c_char_p, ctypes.POINTER(ctypes.c_void_p)]


def connect_signals(window, input, output):

    input.connect_object("activate",  on_calculate, [input, output, output.get_buffer()])

    controller = Gtk.EventControllerKey.new()
    controller.connect("key-pressed", on_key_press)
    window.add_controller(controller)

def on_key_press(controller, keyval, keycode, state):
    if keyval == Gdk.KEY_Escape:
        Gtk.Application.get_default().quit()
        return True
    return False

def on_calculate(args):
    input = args[0].get_text()
    result = tinyexpr.te_interp(input.encode("utf-8"), None)
    end_iter = args[2].get_end_iter()
    args[2].insert(end_iter, "%s = %g\n" % (input, result))

    mark = args[2].create_mark(None, end_iter, False)
    args[1].scroll_to_mark(mark, 0.0, False, 0.0, 0.0)
