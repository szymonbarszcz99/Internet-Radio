#pragma once
#ifndef UNTITLED1_EXCEPTIONS_HANDLER_H
#define UNTITLED1_EXCEPTIONS_HANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include "../gui_event_handler.h"

void no_file();

void no_data();

void empty_link(int line);

void set_name(const char* station_name);

#endif //UNTITLED1_EXCEPTIONS_HANDLER_H
