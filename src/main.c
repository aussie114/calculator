#include <gtk/gtk.h>
#include "main.h"
#include "config.h"
#include "logic.h"

void activate(GtkApplication * app, gpointer user_data)
{
	(void)user_data;
	widget * widgets = (widget *)user_data;

	widgets[ 0] = (widget){gtk_application_window_new(app),                  0,  0,  0,  0};
	widgets[ 1] = (widget){gtk_grid_new(),                                   0,  0,  0,  0};
	widgets[ 2] = (widget){gtk_text_view_new(),                              0,  0,  0,  0};
	widgets[ 3] = (widget){gtk_scrolled_window_new(),                        0,  0,  1,  1};
	widgets[ 4] = (widget){gtk_entry_new(),                                  0,  1,  1,  1};

	GtkEventController * controller = gtk_event_controller_key_new();
	
	config(widgets, controller);
	connect_signals(widgets, controller);

	gtk_widget_grab_focus(INPUT);

	gtk_window_present (GTK_WINDOW (WINDOW));
}

int main (int argc, char ** argv)
{
	GtkApplication * program;
	int status;

	widget widgets[5];

	program = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (program, "activate", G_CALLBACK (activate), widgets);
	status = g_application_run (G_APPLICATION (program), argc, argv);
	g_object_unref (program);
	return status;
}


