#src/config.py
import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Pango, Gdk

def configure(window, grid, scrolled_window, input, output):
    window.set_title("Percentage Calculator")
    window.set_resizable(False)

    margin = 5
    scrolled_window.set_size_request(200, 200)

    window.set_child(grid)
    grid.set_margin_top   (margin)
    grid.set_margin_bottom(margin)
    grid.set_margin_start (margin)
    grid.set_margin_end   (margin)
    grid.set_row_spacing(5)
    grid.set_column_spacing(5)

    scrolled_window.set_child(output)
    grid.attach(scrolled_window, 0, 0, 1, 1)
    grid.attach(input,           0, 1, 1, 1)

    css_provider = Gtk.CssProvider()
    css = """
    * {
        font-family: Monospace;
        font-size: 12pt;
    }
    """
    css_provider.load_from_data(css.encode("utf-8"))
    Gtk.StyleContext.add_provider_for_display(
        Gdk.Display.get_default(),
        css_provider,
        Gtk.STYLE_PROVIDER_PRIORITY_USER
    )
