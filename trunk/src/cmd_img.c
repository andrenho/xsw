/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdlib.h>
#include "cmd_img.h"

CommandImage* cmd_img_new(char* path, int background)
{
	CommandImage* cmd_img = malloc(sizeof(CommandImage));
	if (cmd_img == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	cmd_img->path = path;
	cmd_img->x = DEFAULT_IMG_X;
	cmd_img->y = DEFAULT_IMG_Y;
	cmd_img->scale = DEFAULT_SCALE;
	cmd_img->background = background;
	cmd_img->expand = DEFAULT_EXPAND;
	return cmd_img;
}
