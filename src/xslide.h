#ifndef XSLIDE_H
#define XSLIDE_H

#include <cairo.h>
#include "presentation.h"

void slide_draw(cairo_t *cr, int w, int h, Presentation* p, int slide);

#endif
