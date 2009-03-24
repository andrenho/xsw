#include <string.h>
#include "str.h"

int str_starts_with(char* str, char* start)
{
	int i;
	int v = strlen(start);
	for(i=0; i<v; i++)
		if(str[i] != start[i])
			return 0;
	return 1;
}
