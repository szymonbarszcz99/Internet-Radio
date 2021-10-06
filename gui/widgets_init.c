#include "widgets_init.h"

void create_window(){
    elements->window = gtk_application_window_new(elements->app);

    gtk_window_maximize(elements->window);
    gtk_window_set_deletable(elements->window,FALSE);
    gtk_window_set_title(elements->window,"Internet radio");
    gtk_window_set_resizable(elements->window,FALSE);

}

void create_grid(){

    elements->grid_container = gtk_grid_new();
    gtk_container_add(elements->window,elements->grid_container);

}

void create_buttons() {
    elements->play_button = gtk_button_new_from_icon_name("media-playback-start", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_end(elements->play_button,10);

    elements->pause_button = gtk_button_new_from_icon_name("media-playback-pause", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(elements->pause_button,10);
    gtk_widget_set_margin_end(elements->pause_button,10);

    elements->next_station_button = gtk_button_new_from_icon_name("media-seek-forward",GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_set_margin_start(elements->next_station_button,10);

}

GtkWidget* construct_dialog(const char* error_string){
    return gtk_message_dialog_new(elements->window, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, error_string);

}

void clear_gui_elements(){
    g_object_unref(elements->window);

    g_object_unref(elements->app);

    free(elements);
}