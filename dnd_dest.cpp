// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtk/gtk.h>

static void on_drag_data_received(GtkWidget* widget,
                                  GdkDragContext* drag_context, gint x, gint y,
                                  GtkSelectionData* selection_data, guint info,
                                  guint time, gpointer user_data) {
  if (gtk_selection_data_get_length(selection_data) >= 0) {
    gchar** uris = gtk_selection_data_get_uris(selection_data);
    for (int i = 0; uris[i] != NULL; ++i) {
      g_print("File dragged onto the window: %s\n", uris[i]);
    }
    g_strfreev(uris);
  }
}
static gboolean on_drag_motion(GtkWidget* widget, GdkDragContext* drag_context,
                               gint x, gint y, guint time, gpointer user_data) {
  gtk_drag_highlight(widget);
  return TRUE;
}

int main(int argc, char* argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_set_size_request(window, 400, 400);

  gchar* target = g_strdup("text/uri-list");
  GtkTargetEntry target_entry = {target, 0, 0};
  gtk_drag_dest_set(window, GTK_DEST_DEFAULT_ALL, &target_entry, 1,
                    GDK_ACTION_COPY);
  g_signal_connect(window, "drag-motion", G_CALLBACK(on_drag_motion), NULL);
  g_signal_connect(window, "drag-data-received",
                   G_CALLBACK(on_drag_data_received), NULL);

  g_free(target);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
