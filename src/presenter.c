/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <assert.h>
#include <stdlib.h>
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "presenter.h"
#include "execute.h"
#include "list.h"
#include "cmd_img.h"

#define RATIO 1.0

static TTF_Font* dev_font;

inline static void clear_screen(SDL_Surface* scr)
{
	SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
}

/* Initialize the presenter. Initialize video can be one of:
 *   0 - don't initilize
 *   1 - initialize in a window
 *   2 - initialize in full screen */
Presenter* presenter_initialize(Presentation* p, int initialize_video)
{
	int st;
	Presenter* pr = malloc(sizeof(Presenter));
	if (pr == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	pr->p = p;
	pr->fullscreen = (initialize_video == 2 ? 1 : 0);
	
	if(initialize_video)
		st = SDL_Init(SDL_INIT_VIDEO);
	else
		st = SDL_Init(0);

	if(st == -1)
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());

	// initialize video
	if(initialize_video)
	{
		pr->scr = SDL_SetVideoMode(800, 600, 0, SDL_SWSURFACE|SDL_ANYFORMAT|(initialize_video == 2 ? SDL_FULLSCREEN : 0));
		if(pr->scr == 0)
		{
			fprintf(stderr, "Could not set video mode: %s.\n", SDL_GetError());
			return NULL;
		}
		SDL_WM_SetCaption("xsw", "xsw");
		SDL_WM_SetIcon(IMG_Load(DATADIR "camera.png"), NULL);
		clear_screen(pr->scr);
		if(pr->scr == SDL_GetVideoSurface())
			SDL_Flip(pr->scr);
	}
	else
		pr->scr = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);

	// initialize TTF
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Error initializing SDL_ttf: %s.\n", TTF_GetError());
		return NULL;
	}

	// load developer font
	dev_font = TTF_OpenFont("/usr/share/fonts/TTF/VeraMono.ttf", 10);
	if(!dev_font)
		dev_font = TTF_OpenFont(DATADIR "VeraMono.ttf", 10);

	return pr;
}

static inline void developer_write(Presenter* pr, int x, int y, char* text)
{
	SDL_Color black = { 0, 0, 0, 0 };
	SDL_Color white = { 255, 255, 255, 0 };
	SDL_Surface *sf, *sf_b;
	SDL_Rect r;
	int i, j;
	
	sf = TTF_RenderUTF8_Blended(dev_font, text, white);
	sf_b = TTF_RenderUTF8_Blended(dev_font, text, black);

	for(i=x-1; i<=x+1; i++)
		for(j=y-1; j<=y+1; j++)
			if(i != x || j != y)
			{
				r.x = i;
				r.y = j;
				SDL_BlitSurface(sf_b, NULL, pr->scr, &r);
			}

	r.x = x;
	r.y = y;
	SDL_BlitSurface(sf, NULL, pr->scr, &r);

	SDL_FreeSurface(sf);
	SDL_FreeSurface(sf_b);
}

static inline void developer_mouse_position(Presenter* pr, int x, int y)
{
	char buf[30];
	SDL_Color black = { 0, 0, 0, 0 };
	SDL_Color white = { 255, 255, 255, 0 };
	SDL_Rect r = { SCR_W-50, SCR_H-30, 40, 20 };

	SDL_FillRect(pr->scr, &r, 0);

	sprintf(buf,"%dx%d", x, y);
	SDL_Surface* sf = TTF_RenderText_Shaded(dev_font, buf, white, black);
	r.x += 3; r.y += 3;
	SDL_BlitSurface(sf, NULL, pr->scr, &r);

	if(pr->scr == SDL_GetVideoSurface())
		SDL_UpdateRect(pr->scr, SCR_W - 50, SCR_H - 30, 40, 20);
	SDL_FreeSurface(sf);
}

static inline void developer_grid(Presenter* pr)
{
	int i;
	SDL_Rect r;
	Uint32 white = SDL_MapRGB(pr->scr->format, 255, 255, 255);
	char buf[4];

	developer_write(pr, 0, 0, "0");

	// vertical lines
	for(i=10; i<100; i+=10)
	{
		r.x = (float)i / 100.0 * SCR_W;
		r.y = 0;
		r.h = SCR_H;
		r.w = 1;
		SDL_FillRect(pr->scr, &r, 0);
		r.x++;
		SDL_FillRect(pr->scr, &r, white);
		sprintf(buf, "%d", i);
		developer_write(pr, r.x + 5, r.y, buf);
	}

	// horizontal lines
	for(i=10; i<80; i+=10)
	{
		r.y = (float)i / 100.0 * SCR_W;
		r.x = 0;
		r.w = SCR_W;
		r.h = 1;
		SDL_FillRect(pr->scr, &r, 0);
		r.y++;
		SDL_FillRect(pr->scr, &r, white);
		sprintf(buf, "%d", i);
		developer_write(pr, r.x, r.y + 3, buf);
	}

	// show mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);
	developer_mouse_position(pr,
			(double)x / (double)SCR_W * 100, 
			(double)y / (double)SCR_H * 75);
}


static void gradient(Slide* slide, SDL_Surface* screen)
{
	int r = slide->bg_color[0];
	int g = slide->bg_color[1];
	int b = slide->bg_color[2];
	int r2 = slide->bg_gradient[0];
	int g2 = slide->bg_gradient[1];
	int b2 = slide->bg_gradient[2];

	double cr = r, cg = g, cb = b;

	double r_ratio = (double)(r2-r) / (double)SCR_H * RATIO;
	double g_ratio = (double)(g2-g) / (double)SCR_H * RATIO;
	double b_ratio = (double)(b2-b) / (double)SCR_H * RATIO;

	int i;
	for(i=0; i<SCR_H; i+=RATIO)
	{
		SDL_Rect r = { 0, i, SCR_W, RATIO };
		Uint32 color = SDL_MapRGB(screen->format, (unsigned char)cr, (unsigned char)cg, (unsigned char)cb);
		SDL_FillRect(screen, &r, color);
		// printf("%d - %d %d %d\n", i, (unsigned char)cr, (unsigned char)cg, (unsigned char)cb);
		cr += r_ratio;
		cg += g_ratio;
		cb += b_ratio;
	}
}

// This function caches the next uncached slide. It returns 1 when all
// presentation has been cached, otherwise it returns 0.
int presenter_cache_next(Presenter* pr)
{
	int ns = 0;
	int n_slides = count(pr->p->slides);
	for(; ns < n_slides; ns++)
	{
		Slide* slide = (Slide*)nth(pr->p->slides, ns);
		if(slide->dirty)
		{
			presenter_cache(pr, ns);
			return 0;
		}
	}
	return 1;
}

void presenter_cache(Presenter* pr, int n)
{
	assert(n < count(pr->p->slides));

	// go to slide
	Slide* slide = (Slide*)nth(pr->p->slides, n);

	if(slide->dirty)
	{
		printf("Caching slide %d.\n", n);

		// load the required slide images
		List* commands = slide->commands;
		while(commands)
		{
			execute_parse(pr, commands->data, commands->type);
			commands = commands->next;
		}

		slide->dirty = 0;
	}
}

void presenter_show(Presenter* pr, int n, int developer)
{
	CommandImage* img;
	SDL_Rect r, t;

	presenter_cache(pr, n);

	// go to slide
	Slide* slide = (Slide*)nth(pr->p->slides, n);

	// clear screen
	if(memcmp((char*)slide->bg_color, (char*)slide->bg_gradient, 3) == 0)
	{
		Uint32 bg = SDL_MapRGB(pr->scr->format, slide->bg_color[0], slide->bg_color[1], slide->bg_color[2]);
		SDL_FillRect(pr->scr, NULL, bg);
	}
	else
		gradient(slide, pr->scr);

	List* commands = slide->commands;
	while(commands)
	{
		CommandText* txt;

		switch(commands->type)
		{
		case T_IMAGE:
			img = (CommandImage*)commands->data;
			assert(img->surface);
			r.x = (float)img->x / 100.0 * pr->scr->w;
			r.y = (float)img->y / 75.0 * pr->scr->h;
			SDL_BlitSurface(img->surface, NULL, pr->scr, &r);
			break;
		case T_TEXT:
			txt = (CommandText*)commands->data;
			assert(txt->surface);
			r.x = (float)txt->x / 100.0 * pr->scr->w;
			if(txt->align == 1)
				r.x -= (txt->surface->w / 2);
			else if(txt->align == 2)
				r.x -= txt->surface->w;
			if(txt->y == SET_ON_RUNTIME)
				txt->y = txt->previous->y + txt->previous->h;
			r.y = (float)txt->y / 75.0 * pr->scr->h;

			if(txt->has_border)
			{
				/* we need to work with a copy of r because
				 * SDL_BlitSurface may clip the rectangle's values */
				t.x = r.x; t.y = r.y; // copy r
				t.x -= 1;
				SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &t);
				t.x = r.x; t.y = r.y; // copy r
				t.x += 1;
				SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &t);
				t.x = r.x; t.y = r.y; // copy r
				t.y -= 1;
				SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &t);
				t.x = r.x; t.y = r.y; // copy r
				t.y += 1;
				SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &t);
			}
			SDL_BlitSurface(txt->surface, NULL, pr->scr, &r);
			break;
		default:
			abort();
		}
		commands = commands->next;
	}

	if(developer)
	{
		developer_grid(pr);
		SDL_ShowCursor(SDL_ENABLE);
	}

	if(pr->scr == SDL_GetVideoSurface())
	{
		char title[100];
		sprintf(title, "xsw %d/%d", n+1, count(pr->p->slides));
		SDL_WM_SetCaption(title, title);

		/* sometimes the mouse might 'come back', for example when
		 * changing resolutions, so this avoids the problem */
		if(pr->fullscreen && !developer)
		{
			SDL_ShowCursor(SDL_ENABLE);
			SDL_ShowCursor(SDL_DISABLE);
		}

		SDL_Flip(pr->scr);
	}

	// FIXME - free stuff?
}

// This function gets the next event. The parameter developer says if we're
// in developer mode, and the parameter wait says if the function should
// wait for the next event, or return right away.
PresenterEvent presenter_get_event(Presenter* pr, int developer, int wait)
{
	SDL_Event e;

	pr = pr; // avoids warnings

	if(wait)
		SDL_WaitEvent(&e);
	else
		SDL_PollEvent(&e);

	switch(e.type)
	{
	case SDL_QUIT:
		return PRESENTER_QUIT;

	case SDL_KEYDOWN:
		switch(e.key.keysym.sym)
		{
		case SDLK_F4:				
			if(e.key.keysym.mod & KMOD_ALT)
				return PRESENTER_QUIT;
			break;
		case SDLK_c:				
			if(e.key.keysym.mod & KMOD_CTRL)
				return PRESENTER_QUIT;
			break;
		case SDLK_q:
			return PRESENTER_QUIT;
		case SDLK_PAGEUP:
		case SDLK_UP:
		case SDLK_LEFT:
		case SDLK_BACKSPACE:
			return PRESENTER_PREVIOUS;
		case SDLK_PAGEDOWN:
		case SDLK_DOWN:
			case SDLK_RIGHT:
			case SDLK_SPACE:
				return PRESENTER_NEXT;
			case SDLK_HOME:
				return PRESENTER_FIRST;
			case SDLK_END:
				return PRESENTER_LAST;
			case SDLK_ESCAPE:
				if (pr->fullscreen)
					return PRESENTER_FULLSCREEN;
				break;
			case SDLK_f:
				return PRESENTER_FULLSCREEN;
			case SDLK_d:
				if(e.key.keysym.mod & KMOD_CTRL)
				{
					if(!developer) // developer was set
					{
						// TODO
					}
					return PRESENTER_DEVELOPER;
				}
				break;
			default:
				break;
		}
		break;

	case SDL_MOUSEMOTION:
		if(developer)
			developer_mouse_position(pr,
			  (double)e.motion.x / (double)SCR_W * 100, 
			  (double)e.motion.y / (double)SCR_H * 75);
		break;
	}

	return PRESENTER_NO_EVENT;
}

void presenter_fullscreen(Presenter* pr, int developer)
{
	// fullscreen
	if(SDL_WM_ToggleFullScreen(pr->scr))
		pr->fullscreen = !pr->fullscreen;

	// hide/show mouse
	if(pr->fullscreen && !developer)
		SDL_ShowCursor(SDL_DISABLE);
	else
		SDL_ShowCursor(SDL_ENABLE);
}

void presenter_quit()
{
	SDL_Quit();
}

void presenter_save_image(Presenter* pr, char* filename)
{
	printf("Saving %s.\n", filename);
	SDL_SaveBMP(pr->scr, filename);
}
