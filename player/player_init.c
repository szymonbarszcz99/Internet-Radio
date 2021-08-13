#include "player_init.h"

void player_init(player_data* player,char* first_uri){

    gst_init(NULL, NULL);

    add_prefix(first_uri);

    player->pipeline = gst_parse_launch(first_uri, NULL);

    gst_element_set_state(player->pipeline, GST_STATE_READY);
}