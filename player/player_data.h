#ifndef UNTITLED1_PLAYER_DATA_H
#define UNTITLED1_PLAYER_DATA_H
#include <gst/gst.h>

typedef struct _player_data{
    GstElement* pipeline;
} player_data;

player_data player;

#endif //UNTITLED1_PLAYER_DATA_H
