#include "log.h"

void logger(int level, char *fmt, ...)
{
    char buf[1001]; // this should really be sized appropriately
                    // possibly in response to a call to vsnprintf()
    va_list vl;
    va_start(vl, fmt);

    vsnprintf(buf, sizeof(buf), fmt, vl);

    va_end(vl);

    switch (level)
    {
    case INFO:
        info(buf);
        break;
    case ERROR:
        error(buf);
        break;
    case DEBUG:
        debug(buf);
        break;
    case SUCCESS:
        success(buf);
        break;
    default:
        info(buf);
        break;
    }
}

void info(char *s)
{
    printf(BLU "[INFO] " RESET);
    printf("%s", s);
}

void debug(char *s)
{
    printf(YEL "[DEBUG] " RESET);
    printf("%s", s);
}

void success(char *s)
{
    printf(GRN "[SUCCESS] " RESET);
    printf("%s", s);
}

void error(char *s)
{
    printf(RED "[ERROR] " RESET);
    printf("%s", s);
}