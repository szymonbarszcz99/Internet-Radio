#include "gui_port.h"

void gui_init(GtkApplication* app, struct player_control* player){
    struct gui_elements elements;

    memset(&elements, 0, sizeof(struct gui_elements));

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

void create_window(struct gui_elements* elements){
    elements->window = gtk_application_window_new(elements->app);

    gtk_window_maximize(elements->window);
    gtk_window_set_deletable(elements->window,FALSE);
    gtk_window_set_title(elements->window,"Internet radio");
    gtk_window_set_resizable(elements->window,FALSE);

}

void create_grid(struct gui_elements* elements){

    elements->grid_container = gtk_grid_new();
    gtk_container_add(elements->window,elements->grid_container);

}

void create_buttons(struct gui_elements *elements) {
    elements->play_button = gtk_button_new_from_icon_name("media-playback-start", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_end(elements->play_button,10);

    elements->pause_button = gtk_button_new_from_icon_name("media-playback-pause", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(elements->pause_button,10);
    gtk_widget_set_margin_end(elements->pause_button,10);

    elements->next_station_button = gtk_button_new_from_icon_name("media-seek-forward",GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(elements->next_station_button,10);

}

void connect_callbacks(struct gui_elements *elements, struct player_control *player) {

    g_signal_connect (G_OBJECT (elements->play_button), "clicked", G_CALLBACK (play_callback), player);

    g_signal_connect (G_OBJECT (elements->pause_button), "clicked", G_CALLBACK (pause_callback), player);

}

void play_callback(GtkButton *play_button, struct player_control *player) {
    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
}

void pause_callback(GtkButton *pause_button, struct player_control *player) {
    gst_element_set_state(player->pipeline, GST_STATE_PAUSED);
}

void attach_to_grid(struct gui_elements* elements){
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->label,0,0,3,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container), elements->play_button,0,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->pause_button,1,1,1,1);
    gtk_grid_attach(GTK_GRID(elements->grid_container),elements->next_station_button,2,1,1,1);
}
