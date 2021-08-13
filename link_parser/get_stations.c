#include "get_stations.h"

station get_station(){
    return stations[current_station];
}

station get_next_station(){
    if(current_station == number_of_stations-1){
        current_station = 0;
    }
    else{
        current_station++;
    }
    return get_station();
}

void add_prefix( char* uri){

    char link_prefix[512] = "playbin uri=";

    strcpy(uri, strcat(link_prefix,uri));

}
