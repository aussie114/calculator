#ifndef MAIN_H
#define MAIN_H

#define WINDOW                     widgets[ 0].obj
#define GRID                       widgets[ 1].obj
#define OUTPUT                     widgets[ 2].obj
#define SCROLLED_WINDOW            widgets[ 3].obj
#define INPUT                      widgets[ 4].obj

typedef struct {
	GtkWidget * obj;
	int x, y, w, h;
} widget;

#endif
