#include <string.h>
#include "util.h"

char* trim(char* s)
{
	int st = 0, c = 0;
	int en = strlen(s)-1;

	while(s[st]==' ' || s[st] == '\n' || s[st] == '\t')
	{
		if(!s[st])
			break;
		st++;
	}

	while(s[en]==' ' || s[en] == '\n' || s[en] == '\t')
	{
		if(en == st)
			break;
		en--;
	}

	return strndup(&s[st], en-st+1);
}
