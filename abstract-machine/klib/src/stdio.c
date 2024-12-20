#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  // panic("Not implemented");
  int i = 0;
  va_list args;
  va_start(args, fmt);
  while (*fmt != '\0') {
    if (*fmt == '%') {
      fmt++;
      if (*fmt == 'd') {
        // int num = va_arg(args, int);
        // todo: I haven't finished '%d'.
        panic("Not implemented");
      }
      else if (*fmt == 's') {
        char *str = va_arg(args, char*);
        while (*str != '\0') {
          out[i++] = *str;
          str++;
        }
      }
      else {
        panic("Not implemented");
      }
    }
    else out[i++] = *fmt;
    fmt++;
  }
  out[i] = '\0';
  va_end(args);
  return i;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
