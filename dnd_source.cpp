#include <gtk/gtk.h>
#include <iostream>

static void on_drag_data_get(GtkWidget* widget, GdkDragContext* context,
                             GtkSelectionData* selection_data, guint info, guint time, gpointer user_data)
{
    const gchar* filename = (gchar*)user_data;
    gtk_selection_data_set(selection_data, gtk_selection_data_get_target(selection_data), sizeof(gchar*),
                           (const guchar*)filename, strlen(filename));
}

gboolean on_drag_button_press(GtkWidget* widget, GdkEventButton* event, gpointer data) {
    const gchar* filename = static_cast<const gchar*>(data);
    GtkTargetEntry target_entry = { (gchar*)"text/plain", 0, 0 };
    GtkTargetList* target_list = gtk_target_list_new(&target_entry, 1);
    gint x = static_cast<gint>(event->x);
    gint y = static_cast<gint>(event->y);

    std::cerr << "Received button press at " << x << ", " << y << std::endl;

    GdkDragContext* drag_context = gtk_drag_begin_with_coordinates(widget, target_list, GDK_ACTION_COPY, event->button, (GdkEvent *)event, x, y);

    g_object_set_data(G_OBJECT(drag_context), "filename", const_cast<gchar*>(filename));
    gtk_target_list_unref(target_list);
    return TRUE;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 400, 400);

    GtkWidget* label = gtk_label_new(argv[1]);
    gtk_container_add(GTK_CONTAINER(window), label);

    // Specify the drag source targets and actions
    gtk_drag_source_set(label, GDK_BUTTON1_MASK, nullptr, 0, GDK_ACTION_COPY);

    // Specify the drag destination targets and actions
    gtk_drag_dest_set(label, GTK_DEST_DEFAULT_ALL, nullptr, 0, GDK_ACTION_COPY);

    // Connect the signal handlers for drag events
    g_signal_connect(label, "drag-data-get", G_CALLBACK(on_drag_data_get), argv[1]);
    g_signal_connect(label, "button-press-event", G_CALLBACK(on_drag_button_press), argv[1]);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
