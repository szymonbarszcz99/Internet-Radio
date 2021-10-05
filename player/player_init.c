#include "player_init.h"

void player_init(char* first_uri){

    gst_init(NULL, NULL);

    player.pipeline = gst_parse_launch(first_uri, NULL);

    gst_element_set_state(player.pipeline, GST_STATE_READY);
}