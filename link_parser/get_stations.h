#pragma once
#ifndef UNTITLED1_GET_STATIONS_H
#define UNTITLED1_GET_STATIONS_H
#include "station.h"

static int current_station = 0;

station* get_station();

station* get_next_station();

void add_prefix(char* uri);

#endif //UNTITLED1_GET_STATIONS_H
