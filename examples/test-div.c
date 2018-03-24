#include "../include/fx.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>

float div(float a, float b) {
  if (b == .0)
    return NAN;
  return a / b;
}

FX_MAIN("div(a, b)", {
  FX_CASE("give a > b", {
    FX_TYPE({ float a, b, res; });

    FX_DATA({
        {3, 2, 1.5},
        {4, 2, 2},
        {7, 1, 7},
    });

    FX_EACH(fx) {
      float res = div(fx.a, fx.b);
      if (res == fx.res) {
        FX_PASS("expect (%f / %f) = %f", fx.a, fx.b, fx.res);
      } else {
        FX_FAIL("expect (%f / %f) = %f (but got %f)", fx.a, fx.b, fx.res, res);
      }
    }
  });

  FX_CASE("give a < b", {
    FX_TYPE({ float a, b, res; });

    FX_DATA({
        {2, 4, 0.5},
    });

    FX_EACH(fx) {
      float res = div(fx.a, fx.b);
      if (res == fx.res) {
        FX_PASS("expect (%f / %f) = %f", fx.a, fx.b, fx.res);
      } else {
        FX_FAIL("expect (%f / %f) = %f (but got %f)", fx.a, fx.b, fx.res, res);
      }
    }
  });

  FX_CASE("give a = b", {
    FX_TYPE({ float a, b, res; });

    FX_DATA({
        {4, 4, 1},
        {3, 3, 1},
        {9, 9, 1},
    });

    FX_EACH(fx) {
      float res = div(fx.a, fx.b);
      if (res == fx.res) {
        FX_PASS("expect (%f / %f) = %f", fx.a, fx.b, fx.res);
      } else {
        FX_FAIL("expect (%f / %f) = %f (but got %f)", fx.a, fx.b, fx.res, res);
      }
    }
  });

  FX_CASE("give b = 0", {
    FX_TYPE({ float a, b, res; });

    FX_DATA({
        {4, 0, NAN},
        {3, 0, NAN},
        {9, 0, NAN},
    });

    FX_EACH(fx) {
      float res = div(fx.a, fx.b);
      if (isnan(res) == isnan(fx.res)) {
        FX_PASS("expect (%f / %f) = %f", fx.a, fx.b, fx.res);
      } else {
        FX_FAIL("expect (%f / %f) = %f (but got %f)", fx.a, fx.b, fx.res, res);
      }
    }
  });
})
