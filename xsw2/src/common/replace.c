#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char* replace(char* s, char* term, char* new_term)
{
	char *nw = NULL, *pos;
	char *cur = s;

	assert(s);
	assert(term);
	assert(new_term);

	while(pos = strstr(cur, term))
	{
		nw = (char*)realloc(nw, pos - cur + strlen(new_term));
		strncat(nw, cur, pos-cur);
		strcat(nw, new_term);
		cur = pos + strlen(term);
	}
	strcat(nw, cur);

	free(s);
	return nw;
}
