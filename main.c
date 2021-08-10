#include <stdio.h>
#include <gtk/gtk.h>
#include <gst/gst.h>
#include "player/player_data.h"
#include "player/player_init.h"
#include "gui/gui_init.h"
#include "link_parser/parser_init.h"

int main() {
    GtkApplication* app;
    player_data player;

    memset(&player, 0, sizeof(player_data));

    player_init(&player);

    app = gtk_application_new("org.radio",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (gui_init), &player);

    read_links();

    g_application_run(app,NULL,NULL);
    return 0;
}
