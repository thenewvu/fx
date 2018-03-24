/* fx - A minimal unit test library for C
 * by Vu Le <thenewvu@gmail.com>
 * MIT
 */

#include <stdio.h>

#define FX_EACH(fx)                                                            \
  Fixture fx = fixtures[0];                                                    \
  for (int i = 0; i < sizeof(fixtures) / sizeof(fixtures[0]);                  \
       ++i, fx = fixtures[i])

#define FX_DATA(...) Fixture fixtures[] = __VA_ARGS__

#define FX_TYPE(...) typedef struct __VA_ARGS__ Fixture

#define FX_CASE(name, ...)                                                     \
  do {                                                                         \
    const char *__FX_CASE__ = name;                                            \
    __VA_ARGS__                                                                \
  } while (0)

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define FX_FAIL(...)                                                           \
  do {                                                                         \
    __FX_FAILED__++;                                                           \
    printf(ANSI_COLOR_YELLOW);                                                 \
    printf("FAILED | %s | ", __FX_CASE__);                                     \
    printf(__VA_ARGS__);                                                       \
    printf("\n");                                                              \
    printf(ANSI_COLOR_RESET);                                                  \
  } while (0)

#define FX_PASS(...)                                                           \
  do {                                                                         \
    __FX_PASSED__++;                                                           \
    printf("PASSED | %s | ", __FX_CASE__);                                     \
    printf(__VA_ARGS__);                                                       \
    printf("\n");                                                              \
  } while (0)

#define FX_MAIN(name, ...)                                                     \
  int main() {                                                                 \
    const char *__FX_MAIN__ = name;                                            \
    int __FX_PASSED__ = 0;                                                     \
    int __FX_FAILED__ = 0;                                                     \
    __VA_ARGS__                                                                \
    if (__FX_FAILED__) {                                                       \
      printf(ANSI_COLOR_RED);                                                  \
      printf("FAILED | %s (passed %d/%d)\n", __FX_MAIN__, __FX_PASSED__,       \
             __FX_PASSED__ + __FX_FAILED__);                                   \
      printf(ANSI_COLOR_RESET);                                                \
    } else {                                                                   \
      printf(ANSI_COLOR_GREEN);                                                \
      printf("PASSED | %s (passed %d/%d)\n", __FX_MAIN__, __FX_PASSED__,       \
             __FX_PASSED__ + __FX_FAILED__);                                   \
      printf(ANSI_COLOR_RESET);                                                \
    }                                                                          \
  }
