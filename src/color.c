#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"

unsigned char* color_get(char* desc)
{
	unsigned char* c = malloc(3);

	else
	{
		fprintf(stderr, "Invalid color %s.\n", desc);
		exit(1);
	}
	return c;
}
