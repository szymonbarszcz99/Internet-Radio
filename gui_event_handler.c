#include "gui_event_handler.h"

void clicked_play() {
    play();
}

void clicked_pause() {
    pause_s();
}

void clicked_next() {
    update_label(next());
}

void throw_dialog(const char* error_string){
    construct_dialog(error_string);
}

void update_label(const char* station_name){
    gtk_label_set_text(elements->label,station_name);
}
