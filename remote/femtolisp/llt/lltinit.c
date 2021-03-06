#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <locale.h>
#include "dtypes.h"
#include "timefuncs.h"
#include "ios.h"
#include "random.h"
#include "utf8.h"

double D_PNAN;
double D_NNAN;
double D_PINF;
double D_NINF;
float  F_PNAN;
float  F_NNAN;
float  F_PINF;
float  F_NINF;

int locale_is_utf8;

void llt_init()
{
    locale_is_utf8 = u8_is_locale_utf8(setlocale(LC_ALL, ""));

    randomize();

    ios_init_stdstreams();

    D_PNAN = strtod("+NaN",NULL);
    D_NNAN = -strtod("+NaN",NULL);
    D_PINF = strtod("+Inf",NULL);
    D_NINF = strtod("-Inf",NULL);
#if defined(__TINYC__) // TinyCC
    // TODO: find a better way to query math constants
    F_PNAN = strtod("+NaN",NULL);
    F_NNAN = -strtod("+NaN",NULL);
    F_PINF = strtod("+Inf",NULL);
    F_NINF = strtod("-Inf",NULL);
#else
    F_PNAN = strtof("+NaN",NULL);
    F_NNAN = -strtof("+NaN",NULL);
    F_PINF = strtof("+Inf",NULL);
    F_NINF = strtof("-Inf",NULL);
#endif
}
