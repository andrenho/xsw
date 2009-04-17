/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
# include <io.h>
#else
# include <sys/stat.h>
#endif

#include "x2h_template.h"

static char* write_image(Slide* s, char* filename)
{
	return "teste.png";
}

static void write_slide(Slide* s, char* tpl, char* sl_filename, char* img_filename)
{
	return img_filename;
}

int x2h_template_generate(Presentation* p, char* tpl, PageType page)
{
	page = page; // avoid warnings

	Slide *first = (Slide*)p->slides->data;
	Slide *lst = (Slide*)last(p->slides);

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
	mkdir(p->name);
#else
	mkdir(p->name, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
#endif

	int n = 1;
	List* sds = p->slides;
	while(sds)
	{
		char* img_filename = malloc(512);
		char* sl_filename = malloc(512);
		
		snprintf(img_filename, 511, "%s/%d", p->name, n);
		if(n == 1)
			snprintf(sl_filename, 511, "%s", p->name);
		else
			snprintf(sl_filename, 511, "%s/%d.html", p->name, n);

		img_filename = write_image((Slide*)sds->data, img_filename);
		write_slide((Slide*)sds->data, tpl, sl_filename, img_filename);

		free(img_filename);
		free(sl_filename);

		sds->next;
		n++;
	}
	
	return 1;
}
