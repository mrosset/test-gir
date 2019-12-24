#include <girepository.h>

int main(void) {
  GError *error = NULL;
  GIRepository *gir = g_irepository_get_default();
  g_irepository_require(repository, "CLutter", "1.0", 0, &error);
  if (error) {
    g_error("ERROR: %s\n", error->message);
    return 1;
  }
  return 0;
}
