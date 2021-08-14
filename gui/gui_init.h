#ifndef UNTITLED1_GUI_INIT_H
#define UNTITLED1_GUI_INIT_H

#include <gtk/gtk.h>
#include "../gui_event_handler.h"
#include "gui_elements.h"
#include "widgets_init.h"


void gui_init(GtkApplication* app, player_data* player);

void connect_callbacks(gui_elements* elements, player_data* player);

void play_callback(GtkButton* play_button, player_data *player);

void pause_callback(GtkButton* pause_button, player_data* player);

void next_callback(GtkButton* next_button, player_data* player);

void attach_to_grid(gui_elements* elements);


#endif //UNTITLED1_GUI_INIT_H
