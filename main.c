#include <girepository.h>
#include <glib.h>

int main(void) {
  GError *error = NULL;
  GIRepository *gir = g_irepository_get_default();
  GIBaseInfo *info;
  GIInfoType type;
  const char *expect = "ClutterPaintNode";

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
  if (!g_str_equal(expect, g_type_name(type))) {
    g_error("expected %s got %s\n", expect, g_type_name(type));
  } else {
    g_print("PASS\n");
  }

  g_base_info_ref(info);
  return 0;
}
