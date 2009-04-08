#ifndef CMD_IMAGE_H
#define CMD_IMAGE_H

typedef struct {
	char* path;
	int x, y, w, h;
	double scale;
	int background;
	int expand_horiz;
	int dirty;
#ifdef USE_SDL
	SDL_Surface* surface;
#endif
} CommandImage;

#endif
