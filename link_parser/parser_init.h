#ifndef UNTITLED1_PARSER_INIT_H
#define UNTITLED1_PARSER_INIT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct station{
    char name[512];
    char link[512];
}station;

station *stations;

int count_lines(FILE* file);

void read_links();

#endif //UNTITLED1_PARSER_INIT_H
