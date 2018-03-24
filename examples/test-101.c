#include "../include/fx.h"
#include <stdbool.h>

FX_MAIN("fx101", {
  FX_CASE("some failed", {
    FX_TYPE({ int a, b; });

    FX_DATA({
        {2, 3},
        {2, 5},
        {1, 1},
    });

    FX_EACH(fx) {
      bool res = fx.a == fx.b;
      if (res) {
        pass("expect %d = %d", fx.a, fx.b);
      } else {
        fail("expect %d = %d (but got %d)", fx.a, fx.b, res);
      }
    }
  });
})
