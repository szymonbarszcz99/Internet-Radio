#include "gui_init.h"

void gui_init(GtkApplication* app, player_data* player){
    gui_elements elements;

    memset(&elements, 0, sizeof(gui_elements));

    if(app!=NULL)elements.app = app;
    else{
        printf("GtkApplication was not created");
        exit(1);
    }

    create_window(&elements);

    create_grid(&elements);

    elements.label = gtk_label_new("Click play");

    create_buttons(&elements);

    connect_callbacks(&elements,player);

    attach_to_grid(&elements);

    gtk_widget_show_all(elements.window);
}

void connect_callbacks(gui_elements *elements, player_data *player) {

    g_signal_connect (G_OBJECT (elements->play_button), "clicked", G_CALLBACK (play_callback), player);

    g_signal_connect (G_OBJECT (elements->pause_button), "clicked", G_CALLBACK (pause_callback), player);

}

void play_callback(GtkButton *play_button, player_data *player) {
    station play = get_station();

    player->pipeline = gst_parse_launch(play.link, NULL);

    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
}

void pause_callback(GtkButton *pause_button, player_data *player) {
    gst_element_set_state(player->pipeline, GST_STATE_PAUSED);
}

void next_callback(GtkButton *next_station_button, player_data *player){

}

void attach_to_grid(gui_elements* elements){
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->label,0,0,3,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container), elements->play_button,0,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->pause_button,1,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->next_station_button,2,1,1,1);
}
