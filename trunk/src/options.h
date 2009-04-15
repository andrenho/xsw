/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://gplv3.fsf.org/> */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "presentation.h"

typedef struct {
	int developer;
	int last;
} Options;

Options* options_get(Presentation* presentation, int argc, char* argv[]);

#endif
