#include <stdio.h>
#include <gtk/gtk.h>
#include <gst/gst.h>
#include "player/player_data.h"
#include "player/player_init.h"
#include "gui/gui_init.h"
#include "link_parser/parser_init.h"

int main() {
    GtkApplication* app;
    char start_uri[512];

    memset(&player, 0, sizeof(player_data));

    app = gtk_application_new("org.radio",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (gui_init), NULL);

    read_links();

    add_prefix(strcpy(start_uri,get_station().link));
    player_init(start_uri);

    g_application_run(app,NULL,NULL);
    return 0;
}
