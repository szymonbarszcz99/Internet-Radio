#ifndef UNTITLED1_GUI_ELEMENTS_H
#define UNTITLED1_GUI_ELEMENTS_H

typedef struct gui_elements{
    GtkApplication *app;

    GtkWidget* window;

    GtkWidget* play_button;
    GtkWidget* pause_button;
    GtkWidget* next_station_button;
    GtkWidget* grid_container;
    GtkWidget* label;
}gui_elements;

gui_elements* elements;

#endif //UNTITLED1_GUI_ELEMENTS_H
