#include "gui_event_handler.h"

void clicked_play() {
    play();
}

void clicked_pause() {
    pause_s();
}

void clicked_next() {
    update_label(next());
}

void throw_dialog(const char* error_string){
    GtkWidget* dialog = construct_dialog(error_string);
    g_signal_connect(dialog,"response",clear_and_exit,NULL);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    //free(error_string);
    clear_and_exit();
}

void update_label(const char* station_name){
    gtk_label_set_text(elements->label,station_name);
}

void clear_and_exit(){
    //clear_gui_elements();
    gtk_window_close(elements->window);
    clear_stations();
    free(player.pipeline);
    exit(1);
}