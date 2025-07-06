#include <gtk/gtk.h>
#include "window.h"
#include "grid.h"
#include "input.h"
#include "output.h"

void activate(GtkApplication * app, gpointer user_data)
{
	(void)user_data;

	create_window(app);
	create_grid();
	create_output();
	create_input();
	gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char ** argv)
{
	GtkApplication * program;
	int status;

	program = gtk_application_new ("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (program, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (program), argc, argv);
	g_object_unref (program);
	return status;
}


