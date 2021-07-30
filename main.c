#include <stdio.h>
#include <gtk/gtk.h>
#include <gst/gst.h>
#include "ports/player_control.h"
#include "ports/gui_port.h"

void player_init(struct player_control* player){

    gst_init(NULL, NULL);

    player->pipeline = gst_parse_launch("playbin uri=https://n08a-eu.rcs.revma.com/ypqt40u0x1zuv?rj-ttl=5&rj-tok=AAABeZK5G1oAJcrQH3ZWEgE4hQ", NULL);

    gst_element_set_state(player->pipeline, GST_STATE_READY);
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
