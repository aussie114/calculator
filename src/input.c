#include <gtk/gtk.h>
#include "tinyexpr.h"
#include "grid.h"
#include "output.h"

GtkWidget * input;

void on_input_entered(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	const char * input_text = gtk_editable_get_text(GTK_EDITABLE(input));
	double result = te_interp(input_text, NULL);
	write_to_output(input_text, result);
}

void create_input()
{
	input = gtk_entry_new();
	gtk_grid_attach (GTK_GRID(grid), input, 0, 1, 1, 1);
	gtk_widget_grab_focus(input);
	g_signal_connect(input, "activate", G_CALLBACK(on_input_entered), NULL);
}
