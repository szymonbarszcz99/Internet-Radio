#include "exceptions_handler.h"

void no_file(){
    throw_dialog("No stations.csv file");
}

void no_data(){
    throw_dialog("Empty file");
}

void empty_link(int line){
    char error_text[80];
    sprintf(error_text, "No link on line %d",line);
    throw_dialog(error_text);
}

void set_name(const char* station_name){
    update_label(station_name);
}

