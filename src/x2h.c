/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdio.h>
#include <assert.h>
#include "presentation.h"
#include "file.h"
#include "presenter.h"
#include "list.h"
#include "x2h_options.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char *argv[])
{
	// create a new presentation
	Presentation* p = presentation_new();
	assert(p);

	// read options from command line
     	Options* options = options_get(p, argc, argv);
	// p->filename = "tmp.xsw";
	assert(p);
	assert(p->filename);

	// read file - test if file exists
	if(!file_exists(p->filename))
	{
		fprintf(stderr, "%s is not a valid file.\n", p->filename);
		return 1;
	}

	// get file path
	p->path = file_path(p->filename);
	
	// parse code in the file
	if(!parser_parse(p, p->filename))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// read template file
	
	// generate images and templates
	
	return 0;
}
