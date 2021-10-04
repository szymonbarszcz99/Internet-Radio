#include "player_event_handler.h"

void play(){
    play_stream();
}

void pause_s(){
    pause_stream();
}

void next(){
    station to_change = get_next_station();

    next_stream(to_change.link);
}
