#include <gtk/gtk.h>

#include "gtk_helper_functions.h"
#include "tinyexpr.h"

#define WINDOW 0
#define GRID   1
#define OUTPUT 2
#define INPUT  3

// ------------------------------------------------------------------------------------ function declarations
static void activate (GtkApplication* app, gpointer data);
static void on_expression_entered(GtkWidget * caller, gpointer data);
static gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType modifiers, gpointer user_data);

int main (int argc, char ** argv)
{
	GtkWidget * widgets[4];

	GtkApplication * app;
	int status;

	app = gtk_application_new ("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app, "activate", G_CALLBACK (activate), widgets);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}

static void activate (GtkApplication* app, gpointer data)
{
	GtkWidget ** widgets = (GtkWidget **)data;

    // Create master window
    widgets[ WINDOW ] = ghf_create_window(app, "Calculator", 210, 240, FALSE);

	// Set up input handling
	GtkEventController * controller = gtk_event_controller_key_new();
	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), widgets[ WINDOW ]);
	gtk_widget_add_controller(widgets[WINDOW], controller);

	// Create grid
	widgets[ GRID ] = ghf_create_grid(2,2);
	ghf_widget_set_margin_all( widgets[ GRID ], 5);
	gtk_window_set_child(GTK_WINDOW(widgets[WINDOW]), widgets[ GRID ]);

	// Builder
	GtkWidget * scrolled_window = gtk_scrolled_window_new();
//	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	widgets[ OUTPUT ] = gtk_text_view_new();
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), widgets[ OUTPUT ]);
	gtk_grid_attach(GTK_GRID(widgets[ GRID ]), scrolled_window,   0, 0, 1, 1);

	widgets[INPUT] = ghf_create_widget(gtk_entry_new(), widgets[ GRID ], 0, 1, 1, 1);

	// Configure widgets
	gtk_text_view_set_editable(GTK_TEXT_VIEW(widgets[ OUTPUT ]), false);
	gtk_widget_set_size_request(scrolled_window, 200, 200);
	gtk_entry_set_placeholder_text(GTK_ENTRY(widgets[ INPUT ]), "Expression:");
	gtk_widget_grab_focus(widgets[ INPUT ]);

	// Connect signal
	g_signal_connect(widgets[INPUT], "activate", G_CALLBACK(on_expression_entered), widgets);
	

	gtk_window_present (         GTK_WINDOW(widgets[ WINDOW ]));
}


static void on_expression_entered(GtkWidget * caller, gpointer data)
{
	GtkWidget ** widgets = (GtkWidget **)data;

	// Create output
	gchar * expression = ghf_entry_get_text(widgets[ INPUT ]);
	gchar * output = g_strdup_printf("%s = %g\n", expression, te_interp(expression, 0) );

	ghf_text_view_append_text(widgets[ OUTPUT ], output);

	g_free(output);
}

// ------------------------------------------------------------------------------------------- Input handling
static gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType modifiers, gpointer user_data)
{
    if (keyval == GDK_KEY_Escape) 
	{
        GtkWindow * window = GTK_WINDOW(user_data);
        gtk_window_close(window);
        return TRUE;
    }
    return FALSE;
}
