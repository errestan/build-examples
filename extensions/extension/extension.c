// Include GNU Make headers.
#include <gnumake.h>

// Include Custom headers.
#include "functions.h"

int plugin_is_GPL_compatible;

int my_extension_gmk_setup() {
  // Register the function with make name "to-lower".
  gmk_add_function("to-lower", to_lower, 1, 1, 1);

  // Register the function with make name "to-upper".
  gmk_add_function("to-upper", &to_upper, 1, 1, 1);

  return 1;
}
