/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://gplv3.fsf.org/> */

#ifndef EXECUTE_H
#define EXECUTE_H

#include "presentation.h"
#include "presenter.h"

void execute_parse(Presenter* pr, void* cmd, CommandType type);

#endif
