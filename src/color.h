/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef COLOR_H
#define COLOR_H

typedef struct {
	char *name;
	unsigned char r, g, b;
} Color;

unsigned char* color_get(char* desc);

#endif
