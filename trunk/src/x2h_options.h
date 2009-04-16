/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef X2H_OPTIONS_H
#define X2H_OPTIONS_H

#include "presentation.h"

typedef struct {
	char* html_template;
} Options;

Options* options_get(Presentation* presentation, int argc, char* argv[]);

#endif
