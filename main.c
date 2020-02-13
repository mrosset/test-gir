#include <girepository.h>
#include <glib.h>

static void print_libs(GIRepository *gir, const char *namespace) {
  const char *path = g_irepository_get_typelib_path(gir, namespace);
  const char *libs = g_irepository_get_shared_library(gir, namespace);

  g_print("%s\n", namespace);
  g_print("         path: %s\n", path);
  g_print("    libraries: %s\n", libs);
  g_print("      version: %s\n", g_irepository_get_version(gir, namespace));
}

int main(void) {
  GError *error = NULL;
  GIRepository *gir = g_irepository_get_default();
  GIBaseInfo *info = NULL;
  GIInfoType type;

  g_irepository_require(gir, "Gtk", "3.0", 0, &error);
  g_irepository_require(gir, "Clutter", "1.0", 0, &error);

  if (error) {
    g_error("ERROR: %s\n", error->message);
    return 1;
  }

  info = g_irepository_find_by_name(gir, "Clutter", "PaintNode");

  if (!info) {
    g_error("ERROR: %s\n", "Could not find Clutter PaintNode");
    return 1;
  }

  type = g_registered_type_info_get_g_type(info);

  g_print("base-info: %s\n", g_irepository_find_by_gtype(gir, type));
  g_print("type-name: %s\n", g_type_name(type));

  for (char **arg = g_irepository_get_loaded_namespaces(gir); *arg; ++arg) {
    print_libs(gir, *arg);
  }
  g_base_info_ref(info);
  return 0;
}
