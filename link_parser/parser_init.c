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
    links = fopen("../stations.csv", "r");

    if(links == NULL){
        printf("Cannot open file");
        exit(2);
    }

    number_of_stations = count_lines(links);
    stations = malloc(number_of_stations * sizeof(station));

    for(int i=0; i<number_of_stations; i++){
        char tmp_line[1024];

        fgets(tmp_line, 1024, links);
        tmp_line[strlen(tmp_line)-1] = '\0';    //delete new line from link

        char* token = strtok(tmp_line,",");
        memcpy(stations[i].name,token, strlen(token));

        token = strtok(NULL,",");
        memcpy(stations[i].link,token,strlen(token));

    }

    for(int i=0; i<number_of_stations; i++){
        printf("%s\n%s\n",stations[i].name,stations[i].link);
    }
}

