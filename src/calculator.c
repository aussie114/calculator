#include <gtk/gtk.h>
#include "tinyexpr.h"
#include "grid.h"

GtkWidget * input;
struct 
{
	GtkWidget * viewer;
	GtkWidget * scrolled_window;
	GtkTextBuffer * buffer;
	GtkTextIter iter;
	GtkTextMark * mark;
} output;

void on_input_entered(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	// Evaluate input
	const char * input_text = gtk_editable_get_text(GTK_EDITABLE(input));
	double result = te_interp(input_text, NULL);

	// Create and write output
	gchar * output_text = g_strdup_printf("%s = %g\n", input_text, result);
	gtk_text_buffer_get_end_iter(output.buffer, &output.iter);
	gtk_text_buffer_insert(output.buffer, &output.iter, output_text, -1);
	g_free(output_text);

    // Scroll to the end
    output.mark = gtk_text_buffer_create_mark(output.buffer, NULL, &output.iter, FALSE);
    gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(output.viewer), output.mark, 0.0, FALSE, 0.0, 1.0);
    gtk_text_buffer_delete_mark(output.buffer, output.mark);
}

void create_calculator()
{
	input = gtk_entry_new();
	output.viewer = gtk_text_view_new();
	output.scrolled_window = gtk_scrolled_window_new();
	output.buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(output.viewer));

	gtk_widget_set_size_request(output.scrolled_window, 200, 200);
	gtk_scrolled_window_set_child( GTK_SCROLLED_WINDOW(output.scrolled_window), output.viewer);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(output.viewer), false);
	gtk_grid_attach (GTK_GRID(grid), output.scrolled_window, 0, 0, 1, 1);
	gtk_grid_attach (GTK_GRID(grid), input,                  0, 1, 1, 1);
	g_signal_connect(input, "activate", G_CALLBACK(on_input_entered), NULL);

	gtk_widget_grab_focus(input);
}
