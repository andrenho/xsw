/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef CMD_IMG_H
#define CMD_IMG_H

#ifdef USE_SDL
#	include "SDL.h"
#endif

#define DEFAULT_IMG_X 	0
#define DEFAULT_IMG_Y	0
#define DEFAULT_SCALE	1
#define DEFAULT_EXPAND	vertical

typedef enum { vertical, horizontal } ExpandType;

typedef struct {
	char* path;
	double x, y;
	double scale;
	int background;
	ExpandType expand;
#ifdef USE_SDL
	SDL_Surface* surface;
#endif
} CommandImage;

CommandImage* cmd_img_new(char* path, int background);

#endif
