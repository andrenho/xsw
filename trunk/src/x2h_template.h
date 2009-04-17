/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef X2H_TEMPLATE_H
#define X2H_TEMPLATE_H

#include "presentation.h"
#include "slide.h"

typedef enum { ONE_FILE_PER_SLIDE } PageType;

int x2h_template_generate(Presentation* p, char* tpl, PageType page);

#endif
