#include "parser_init.h"

int count_lines(FILE* file){
    int lines = 0;
    char read_sign;
    while((read_sign = getc(file)) != EOF){
        if(read_sign == '\n')lines++;
    }
    rewind(file);
    printf("%d",lines);
    return lines;
}

void read_links(){
    FILE* links;
    links = fopen("../stations.txt", "r");

    if(links == NULL){
        printf("Cannot open file");
        exit(2);
    }

    number_of_stations = count_lines(links)/2;
    stations = malloc(number_of_stations * sizeof(station));

    for(int i=0; i<number_of_stations; i++){
        char station_link[512];

        fgets(stations[i].name, 512, links);
        fgets(stations[i].link, 512, links);

        stations[i].link[strcspn(stations[i].link,"\n")] = 0;
    }

    for(int i=0; i<number_of_stations; i++){
        printf("%s\n%s\n",stations[i].name,stations[i].link);
    }
}

