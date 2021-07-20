#include <stdio.h>
#include <gtk/gtk.h>
#include <gst/gst.h>

struct player_control{
    GstElement* pipeline;
};

void player_init(struct player_control* player){

    gst_init(NULL, NULL);

    player->pipeline = gst_parse_launch("playbin uri=https://n08a-eu.rcs.revma.com/ypqt40u0x1zuv?rj-ttl=5&rj-tok=AAABeZK5G1oAJcrQH3ZWEgE4hQ", NULL);

    gst_element_set_state(player->pipeline, GST_STATE_READY);
}

void play_callback(GtkButton* play_button,struct player_control *player){
    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
}

void pause_callback(GtkButton* pause_button,struct player_control* player){
    gst_element_set_state(player->pipeline, GST_STATE_PAUSED);
}

void gui_init(GtkApplication* app, struct player_control* player){
    GtkWidget* window;

    GtkWidget* play_button;
    GtkWidget* pause_button;
    GtkWidget* next_station_button;
    GtkWidget* grid_container;
    GtkWidget* label;

    window = gtk_application_window_new(app);
    gtk_window_maximize(window);
    gtk_window_set_deletable(window,FALSE);
    gtk_window_set_title(window,"Internet radio");

    grid_container = gtk_grid_new();
    gtk_container_add(window,grid_container);

    label = gtk_label_new("Click play");

    play_button = gtk_button_new_from_icon_name("media-playback-start", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_end(play_button,10);
    g_signal_connect (G_OBJECT (play_button), "clicked", G_CALLBACK (play_callback), player);

    pause_button = gtk_button_new_from_icon_name("media-playback-pause", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(pause_button,10);
    gtk_widget_set_margin_end(pause_button,10);
    g_signal_connect (G_OBJECT (pause_button), "clicked", G_CALLBACK (pause_callback), player);

    next_station_button = gtk_button_new_from_icon_name("media-seek-forward",GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(next_station_button,10);

    gtk_grid_attach(GTK_GRID(grid_container),label,0,0,3,1);
    gtk_grid_attach(GTK_GRID(grid_container), play_button,0,1,1,1);
    gtk_grid_attach(GTK_GRID(grid_container),pause_button,1,1,1,1);
    gtk_grid_attach(GTK_GRID(grid_container),next_station_button,2,1,1,1);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication* app;
    struct player_control* player;

    memset(player, 0, sizeof(struct player_control));

    player_init(player);

    app = gtk_application_new("org.radio",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (gui_init), player);

    g_application_run(app,NULL,NULL);
    return 0;
}
