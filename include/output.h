#ifndef OUTPUT_H
#define OUTPUT_H
typedef struct 
{
	GtkWidget * viewer;
	GtkWidget * scrolled_window;
	GtkTextBuffer * buffer;
	GtkTextIter iter;
	GtkTextMark * mark;
} text_view;
extern text_view output;
void write_to_output(const char * input_text, double result);
void create_output();
#endif
