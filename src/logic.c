#include <gtk/gtk.h>
#include "main.h"
#include "tinyexpr.h" 

gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
    (void)controller;
    (void)keycode;
    (void)state;
	if (keyval == GDK_KEY_Escape) 
	{
		gtk_window_destroy(GTK_WINDOW(user_data));
		return TRUE;
	}
		return FALSE;
}

void on_input_entered(GtkWidget * caller, gpointer data)
{
	(void)caller;
	widget * widgets = (widget*)data;
	GtkTextBuffer * buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(OUTPUT));
	GtkTextIter end_iter;

	// Interp expression
	const char * input = gtk_editable_get_text(GTK_EDITABLE(INPUT));
	double result = te_interp(input, NULL);

	// create output
	int output_text_size = 1 + snprintf(NULL, 0,  "%s = %g\n", input, result);
	char output_text[output_text_size];
	snprintf(output_text, output_text_size,       "%s = %g\n", input, result);

	// Write output
	gtk_text_buffer_get_end_iter(buffer, &end_iter);
	gtk_text_buffer_insert(buffer, &end_iter, output_text, -1);

    // Scroll to the end
    GtkTextMark * mark = gtk_text_buffer_create_mark(buffer, NULL, &end_iter, FALSE);
    gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(OUTPUT), mark, 0.0, FALSE, 0.0, 1.0);
    gtk_text_buffer_delete_mark(buffer, mark);
}

void connect_signals(widget * widgets, GtkEventController * controller)
{
	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), WINDOW);
	g_signal_connect(INPUT, "activate", G_CALLBACK(on_input_entered), widgets);
}
