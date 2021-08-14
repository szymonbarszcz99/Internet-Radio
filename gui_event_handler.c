#include "gui_event_handler.h"

void clicked_play() {
    station to_play = get_station();

    play(to_play.link, player);
}

void clicked_pause() {
    pause_stream();
}

void clicked_next() {
    station to_change = get_next_station();

    next_station(to_change.link);
}
