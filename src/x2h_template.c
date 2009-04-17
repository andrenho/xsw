/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
# include <io.h>
#else
# include <sys/stat.h>
#endif

#include "x2h_template.h"
#include "presenter.h"

Presenter* pr;

typedef enum { First, Normal, Last } LinkType;

static char* write_image(Presenter* pr, Slide* s, char* filename)
{
	List *sds = pr->p->slides;
	int n=0;
	while((Slide*)sds->data != s)
	{
		sds = sds->next;
		n++;
		if(!sds)
			abort();
	}

	sprintf(filename, "%s.bmp", filename); // TODO

	presenter_show(pr, n, 0);
	presenter_save_image(pr, filename);

	return filename;
}

static void write_slide(Slide* s, char* tpl, char* sl_filename, char* img_filename, LinkType link)
{
}

int x2h_template_generate(Presentation* p, char* tpl, PageType page)
{
	page = page; // avoid warnings

	Slide *lst = (Slide*)last(p->slides);
	pr = presenter_initialize(p, 0);

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
		LinkType link = Normal;

		snprintf(img_filename, 511, "%s/%d", p->name, n);
		if(n == 1)
		{
			snprintf(sl_filename, 511, "%s", p->name);
			link = First;
		}
		else
			snprintf(sl_filename, 511, "%s/%d.html", p->name, n);

		if((Slide*)sds->data == lst)
			link = Last;

		img_filename = write_image(pr, (Slide*)sds->data, img_filename);
		write_slide((Slide*)sds->data, tpl, sl_filename, img_filename, link);

		free(img_filename);
		free(sl_filename);

		sds = sds->next;
		n++;
	}
	
	return 1;
}
