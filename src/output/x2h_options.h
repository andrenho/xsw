#ifndef X2H_OPTIONS_H
#define X2H_OPTIONS_H

#include "presentation.h"

typedef struct {} Options;

Options* options_get(Presentation* presentation, int argc, char* argv[]);

#endif
