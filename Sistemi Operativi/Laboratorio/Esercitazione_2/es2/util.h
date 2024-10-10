// util.h

#ifndef UTIL_H
#define UTIL_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// Intercetta CTRL+C e esegue una funzione di pulizia prima di uscire
void setQuitHandler(void(*f)());

// Macro per gestire gli errori
#define handle_error_en(en, msg) \
    do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

#endif // UTIL_H