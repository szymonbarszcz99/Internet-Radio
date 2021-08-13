#include "player_functions.h"

void play(const char* uri, player_data* player){
    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
}

void next_station(const char* uri, player_data* player){
    gst_element_set_state(player->pipeline, GST_STATE_READY);

    g_object_set(player->pipeline, "uri", uri,NULL);

    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
}

void pause_stream(player_data *player) {
    gst_element_set_state(player->pipeline, GST_STATE_PAUSED);
}
