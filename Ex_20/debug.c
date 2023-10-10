#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

static int stored_debug_level = 0;

void set_debug_level(int debug_level) {
    stored_debug_level = debug_level;
}

int dprintf(int debug_level, const char *fmt, ...) {
    if (debug_level <= stored_debug_level) {
        fprintf(stderr, "[DBG%d] ", debug_level);

        va_list args;
        va_start(args, fmt);
        int ret = vfprintf(stderr, fmt, args);
        va_end(args);

        return ret;
    }
    return 0;
}
