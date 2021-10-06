#ifndef UNTITLED1_WIDGETS_INIT_H
#define UNTITLED1_WIDGETS_INIT_H

#include <gtk/gtk.h>
#include "gui_elements.h"

void create_window();

void create_grid();

void create_buttons();

GtkWidget* construct_dialog(const char* error_string);

void clear_gui_elements();
#endif //UNTITLED1_WIDGETS_INIT_H
