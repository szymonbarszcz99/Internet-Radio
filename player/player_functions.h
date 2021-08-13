#ifndef UNTITLED1_PLAYER_FUNCTIONS_H
#define UNTITLED1_PLAYER_FUNCTIONS_H
#include "player_data.h"

void play(const char* uri, player_data* player);

void next_station(const char* uri, player_data* player);

void pause_stream(player_data* player);

#endif //UNTITLED1_PLAYER_FUNCTIONS_H
