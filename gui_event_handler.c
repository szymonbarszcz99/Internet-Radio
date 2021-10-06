#include "gui_event_handler.h"

void clicked_play() {
    play();
}

void clicked_pause() {
    pause_s();
}

void clicked_next() {
    next();
}

void throw_dialog(const char* error_string){
    construct_dialog(error_string);
}
