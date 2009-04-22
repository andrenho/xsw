#include <string.h>
#include <ctype.h>
#include "util.h"

char* trim(char* s)
{
	int st = 0, c = 0;
	int en = strlen(s)-1;

	while(isspace(s[st]) != 0)
	{
		if(!s[st])
			break;
		st++;
	}

	while(isspace(s[en]) != 0)
	{
		if(en <= st)
			break;
		en--;
	}

	return strndup(&s[st], en-st+1);
}
