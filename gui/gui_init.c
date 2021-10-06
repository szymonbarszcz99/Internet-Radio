#include "gui_init.h"

void gui_init(GtkApplication* app){

    elements = malloc(sizeof(gui_elements));

    memset(elements, 0, sizeof(gui_elements));

    if(app!=NULL)elements->app = app;
    else{
        printf("GtkApplication was not created");
        exit(1);
    }

    create_window();

    create_grid();

    elements->label = gtk_label_new("Click play");

    create_buttons();

    connect_callbacks();

    attach_to_grid();

    gtk_widget_show_all(elements->window);

}

void connect_callbacks() {

    g_signal_connect (G_OBJECT (elements->play_button), "clicked", G_CALLBACK (clicked_play), NULL);

    g_signal_connect (G_OBJECT (elements->pause_button), "clicked", G_CALLBACK (clicked_pause), NULL);

    g_signal_connect(G_OBJECT(elements->next_station_button),"clicked", G_CALLBACK(clicked_next), NULL);
}

void attach_to_grid(){
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->label,0,0,3,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container), elements->play_button,0,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->pause_button,1,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->next_station_button,2,1,1,1);
}

