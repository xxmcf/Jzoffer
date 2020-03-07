#include "pub.h"
#include <stdarg.h>
#include <iostream>

void log(const char* fmt, ...)
{
    va_list argstr;
    va_start(argstr, fmt);
    vprintf(fmt, argstr);
    printf("\n");
    va_end(argstr);
}
