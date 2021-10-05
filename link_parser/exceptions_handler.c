#include "exceptions_handler.h"

void no_file(){
    puts("No file stations.csv");
    exit(1);
}

void no_data(){
    puts("No data in file");
    exit(2);
}

void empty_link(int line){
    printf("No link on line %d", line);
    exit(3);
}

