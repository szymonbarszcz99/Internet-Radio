#include <stdio.h>
#include <gtk/gtk.h>

void gui_init(GtkApplication* app){
    GtkWidget* window;
    window= gtk_application_window_new(app);
    gtk_window_maximize(window);
    gtk_window_set_deletable(window,FALSE);
    gtk_window_set_title(window,"Radio internetowe");
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication* app;

    app = gtk_application_new("org.radio",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (gui_init), NULL);

    g_application_run(app,NULL,NULL);
    return 0;
}
