#ifndef UNTITLED1_GUI_EVENT_HANDLER_H
#define UNTITLED1_GUI_EVENT_HANDLER_H

#include "player_event_handler.h"
#include "gui/widgets_init.h"

void clicked_play();

void clicked_pause();

void clicked_next();

void throw_dialog(const char* error_string);

void update_label(const char* station_name);

void clear_and_exit();

#endif //UNTITLED1_GUI_EVENT_HANDLER_H
