#include <gtk/gtk.h>
#include "grid.h"
#include "output.h"

text_view output;

void write_to_output(const char * input_text, double result)
{
	// Create and write output
	gchar * output_text = g_strdup_printf("%s = %g\n", input_text, result);
	gtk_text_buffer_get_end_iter(output.buffer, &output.iter);
	gtk_text_buffer_insert(output.buffer, &output.iter, output_text, -1);

    // Scroll to the end
    output.mark = gtk_text_buffer_create_mark(output.buffer, NULL, &output.iter, FALSE);
    gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(output.viewer), output.mark, 0.0, FALSE, 0.0, 1.0);
    gtk_text_buffer_delete_mark(output.buffer, output.mark);

	g_free(output_text);
}

void create_output()
{
	output.viewer = gtk_text_view_new();
	output.scrolled_window = gtk_scrolled_window_new();
	output.buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(output.viewer));
	gtk_widget_set_size_request(output.scrolled_window, 200, 200);
	gtk_scrolled_window_set_child( GTK_SCROLLED_WINDOW(output.scrolled_window), output.viewer);
	gtk_grid_attach (GTK_GRID(grid), output.scrolled_window, 0, 0, 1, 1);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(output.viewer), false);
}
