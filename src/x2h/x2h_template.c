/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
# include <io.h>
#else
# include <sys/stat.h>
#endif

#include <stdio.h>
#include "x2h_template.h"
#include "presenter.h"
#include "util.h"

Presenter* pr;

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

static void write_slide(char* tpl, char* img_filename, int first, int last, char* path, int n)
{
	char pfn[512], fn[512], ffn[512];
	if(n == 1)
	{
		sprintf(fn, "%s.html", path);
		sprintf(ffn, "%s/%d.html", path, n+1);
	}
	else if(n == 2)
	{
		sprintf(pfn, "../%s.html", path);
		sprintf(fn, "%s/%d.html", path, n);
		sprintf(ffn, "%d.html", n+1);
	}
	else
	{
		sprintf(pfn, "%d.html", n-1);
		sprintf(fn, "%s/%d.html", path, n);
		sprintf(ffn, "%d.html", n+1);
	}

	FILE *f = fopen(fn, "w");
	char* r = strdupa(tpl);
	char *str, *tok;
	int active = 1;

	while(str = strsep(&r, "%"))
	{
		tok = trim(str);
		if(strcmp(tok, "prev_start") == 0)
		{
			if(first)
				active = 0;
		}
		else if(strcmp(tok, "prev_else") == 0)
		{
			if(first)
				active = 1;
			else
				active = 0;
		}
		else if(strcmp(tok, "prev_end") == 0)
		{
			active = 1;
		}
		else if(strcmp(tok, "prev_link") == 0)
		{
			if(active)
				fprintf(f, "%s", pfn);
		}
		else if(strcmp(tok, "slide") == 0)
		{
			if(active)
			{
				if(n == 1)
					fprintf(f, "%s", img_filename);
				else
					fprintf(f, "../%s", img_filename);
			}
		}
		else if(strcmp(tok, "next_start") == 0)
		{
			if(last)
				active = 0;
		}
		else if(strcmp(tok, "next_else") == 0)
		{
			if(last)
				active = 1;
			else
				active = 0;
		}
		else if(strcmp(tok, "next_end") == 0)
		{
			active = 1;
		}
		else if(strcmp(tok, "next_link") == 0)
		{
			if(active)
				fprintf(f, "%s", ffn);
		}
		else if(strcmp(tok, "presentation_name") == 0)
		{
			fprintf(f, "%s", path);
		}
		else if(strcmp(tok, "path_name") == 0)
		{
			if(active)
			{
				if(n == 1)
					fprintf(f, "%s", path);
				else
					fprintf(f, "../%s", path);
			}
		}
		else 
		{
			if(active)
				fprintf(f, "%s", str);
		}
  
		free(tok);
	}

	fclose(f);
}

int x2h_template_generate(Presentation* p, char* tpl, PageType page)
{
	page = page; // avoid warnings

	Slide *lst = (Slide*)last(p->slides);
	pr = presenter_initialize(p, 0);
	int first = 0, last = 0;

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
	mkdir(p->name);
#else
	mkdir(p->name, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
#endif

	int n = 1;
	List* sds = p->slides;
	while(sds)
	{
		char* img_filename = alloca(512);

		if(n == 1)
			first = 1;
		else
			first = 0;
		
		snprintf(img_filename, 511, "%s/%d", p->name, n);

		if((Slide*)sds->data == lst)
			last = 1;

		img_filename = write_image(pr, (Slide*)sds->data, img_filename);
		write_slide(tpl, img_filename, first, last, p->name, n);

		sds = sds->next;
		n++;
	}
	
	// TODO do this in C
	char cmd[512];
	sprintf(cmd, "cp %sback.png %s/", DATADIR, p->name);
	system(cmd);
	sprintf(cmd, "cp %sforward.png %s/", DATADIR, p->name);
	system(cmd);

	return 1;
}
