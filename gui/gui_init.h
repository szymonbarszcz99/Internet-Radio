#ifndef UNTITLED1_GUI_INIT_H
#define UNTITLED1_GUI_INIT_H

#include <gtk/gtk.h>
#include "../gui_event_handler.h"
#include "gui_elements.h"
#include "widgets_init.h"


void gui_init(GtkApplication* app);

void connect_callbacks();

void attach_to_grid();


#endif //UNTITLED1_GUI_INIT_H
