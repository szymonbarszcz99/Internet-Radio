#include <stdio.h>
#include "player/player_init.h"
#include "gui/gui_init.h"
#include "link_parser/parser_init.h"

void start_app(GtkApplication* app){
    char start_uri[512];
    gui_init(app);
    read_links();
    add_prefix(strcpy(start_uri,get_station()->link));
    player_init(start_uri);
    clicked_play();
}

int main() {
    GtkApplication* app;

    memset(&player, 0, sizeof(player_data));

    app = gtk_application_new("org.radio",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (start_app), NULL);
    g_application_run(app,NULL,NULL);
    return 0;
}
