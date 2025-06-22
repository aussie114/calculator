#include <gtk/gtk.h>
#include "main.h"

void config(widget * widgets, GtkEventController * controller)
{
	// Window
	gtk_window_set_title        ( GTK_WINDOW (WINDOW), "Window");
	gtk_window_set_default_size ( GTK_WINDOW (WINDOW), 200, 200);
	gtk_window_set_resizable    ( GTK_WINDOW (WINDOW), FALSE);

	// grid
	gtk_window_set_child (GTK_WINDOW (WINDOW), GRID);
	gtk_widget_set_margin_top   (GRID, 4);
	gtk_widget_set_margin_end   (GRID, 4);
	gtk_widget_set_margin_bottom(GRID, 4);
	gtk_widget_set_margin_start (GRID, 4);
	gtk_grid_set_column_spacing(GTK_GRID(GRID), 2);
	gtk_grid_set_row_spacing(GTK_GRID(GRID), 2);

	// scrolled window
	gtk_widget_set_size_request(SCROLLED_WINDOW, 200, 200);
	gtk_scrolled_window_set_child( GTK_SCROLLED_WINDOW(SCROLLED_WINDOW), OUTPUT);

	// Output
	gtk_text_view_set_editable(GTK_TEXT_VIEW(OUTPUT), false);
	gtk_widget_add_css_class(OUTPUT, "monospace");
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_string(provider,
		".monospace { font-family: monospace; font-size: 10pt; }");
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(),
		GTK_STYLE_PROVIDER(provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);

	for (int i = 3; i < 5; i++)
	{
		gtk_grid_attach (GTK_GRID(GRID), widgets[i].obj, widgets[i].x, widgets[i].y, widgets[i].w ,widgets[i].h);
	}

	gtk_widget_add_controller(WINDOW, controller);

}
