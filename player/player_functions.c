#include "player_functions.h"

void play_stream(){
    gst_element_set_state(player.pipeline, GST_STATE_PLAYING);
}

void next_stream(const char* uri){
    gst_element_set_state(player.pipeline, GST_STATE_READY);

    g_object_set(player.pipeline, "uri", uri,NULL);

    gst_element_set_state(player.pipeline, GST_STATE_PLAYING);
}

void pause_stream() {
    gst_element_set_state(player.pipeline, GST_STATE_PAUSED);
}
