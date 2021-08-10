#include "parser_init.h"

int count_lines(FILE* file){
    int lines = 0;
    char read_sign;
    while((read_sign = getc(file)) != EOF){
        if(read_sign == '\n')lines++;
    }
    rewind(file);
    return ++lines;
}

void read_links(){
    FILE* links;
    links = fopen("../stations.txt", "r");

    if(links == NULL){
        printf("Cannot open file");
        exit(2);
    }

    int lines = count_lines(links);
    char stations_array[lines/2][512];
    char names_array[lines/2][512];

    for(int i=0; i<lines/2; i++){
        fgets(names_array[i], 512, links);
        fgets(stations_array[i], 512, links);

        printf("%s", names_array[i]);
        printf("%s", stations_array[i]);
    }
}

