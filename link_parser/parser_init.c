#include "parser_init.h"

int count_lines(FILE* file){
    int lines = 0;
    char read_sign;
    while((read_sign = getc(file)) != EOF){
        if(read_sign == '\n')lines++;
    }
    rewind(file);
    return lines;
}

void read_links(){
    FILE* links;
    links = fopen("../stations.txt", "r");

    if(links == NULL){
        printf("Cannot open file");
        exit(2);
    }

    int lines = count_lines(links);
    stations = malloc(lines/2 * sizeof(station));

    for(int i=0; i<lines/2; i++){
        char station_link[512];
        char link_prefix[512] = "playbin uri=";

        fgets(stations[i].name, 512, links);
        fgets(station_link, 512, links);

        station_link[strcspn(station_link,"\n")] = 0;

        strcpy(stations[i].link, strcat(link_prefix,station_link));
    }

    for(int i=0; i<lines/2; i++){
        printf("%s\n%s\n",stations[i].name,stations[i].link);
    }
}

