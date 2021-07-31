#include "player_init.h"

void player_init(player_data* player){

    gst_init(NULL, NULL);

    player->pipeline = gst_parse_launch("playbin uri=https://n08a-eu.rcs.revma.com/ypqt40u0x1zuv?rj-ttl=5&rj-tok=AAABeZK5G1oAJcrQH3ZWEgE4hQ", NULL);

    gst_element_set_state(player->pipeline, GST_STATE_READY);
}