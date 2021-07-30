#ifndef UNTITLED1_GUI_PORT_H
#define UNTITLED1_GUI_PORT_H

#include <gtk/gtk.h>
#include "player_control.h"

struct gui_elements{
    GtkApplication *app;

    GtkWidget* window;

    GtkWidget* play_button;
    GtkWidget* pause_button;
    GtkWidget* next_station_button;
    GtkWidget* grid_container;
    GtkWidget* label;
};

void gui_init(GtkApplication* app, struct player_control* player);

void create_window(struct gui_elements* elements);

void create_grid(struct gui_elements* elements);

void create_buttons(struct gui_elements* elements);

void connect_callbacks(struct gui_elements* elements, struct player_control* player);

void play_callback(GtkButton* play_button,struct player_control *player);

void pause_callback(GtkButton* pause_button,struct player_control* player);

void attach_to_grid(struct gui_elements* elements);


#endif //UNTITLED1_GUI_PORT_H
