#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void create_window(GApplication *app, const char *uri) {
  GtkWidget *window, *view, *label, *box;

  window = gtk_application_window_new(GTK_APPLICATION(app));
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  view = webkit_web_view_new();
  label = gtk_label_new("Primary");

  if (g_application_get_is_remote(app)) {
    gtk_label_set_label(GTK_LABEL(label), "Remote");
  }

  webkit_web_view_load_uri(WEBKIT_WEB_VIEW(view), uri);

  g_signal_connect(window, "destroy", G_CALLBACK(g_application_quit), NULL);

  gtk_box_pack_start(GTK_BOX(box), view, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), box);

  gtk_widget_show_all(window);
}

void activate_cb(GApplication *app, gpointer user_data) {
  g_print("**** ACTIVATE\n");
  create_window(app, "https://gnu.org");
}

void open_cb(GApplication *app, GFile **files, gint n_files, gchar *hint,
             gpointer user_data) {

  g_print("**** OPEN\n");
  for (int i = 0; i < n_files; i++) {
    create_window(app, g_file_get_uri(files[i]));
  }
}

int main(int argc, char **argv) {

  GtkApplication *app;

  app = gtk_application_new("org.gnu.testgir", G_APPLICATION_HANDLES_OPEN);

  g_signal_connect(G_APPLICATION(app), "activate", G_CALLBACK(activate_cb),
                   NULL);
  g_signal_connect(G_APPLICATION(app), "open", G_CALLBACK(open_cb), NULL);

  return g_application_run(G_APPLICATION(app), argc, argv);
}
