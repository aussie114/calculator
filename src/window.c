#include <gtk/gtk.h>

GtkWidget * window;

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

void create_window(GtkApplication * program)
{
	window   = gtk_application_window_new(program);
	gtk_window_set_title        ( GTK_WINDOW (window), "calculator");
	gtk_window_set_default_size ( GTK_WINDOW (window), 200, 200);
	gtk_window_set_resizable    ( GTK_WINDOW (window), FALSE);

	GtkEventController * controller = gtk_event_controller_key_new();
	gtk_widget_add_controller(window, controller);
	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), window);

    GtkCssProvider * provider = gtk_css_provider_new();
    gtk_css_provider_load_from_string(provider, "* { font-family: monospace; font-size: 17px; }");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	g_object_unref(provider);
}

