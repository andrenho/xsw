/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

List* append_t(List* list, void* data, int type)
{
	List* original = list;

	if(!list)
	{
		list = malloc(sizeof(List));
		if (list == NULL) 
		{
			fprintf(stderr, "Not enough memory\n");
			exit(1);		
		}
		list->prev = NULL;
		list->next = NULL;
		list->data = data;
		list->type = type;
		list->dirty = 1;
		original = list;
	}
	else
	{
		while(list->next)
			list = list->next;

		list->next = malloc(sizeof(List));
		if (list->next == NULL) 
		{
			fprintf(stderr, "Not enough memory\n");
			exit(1);		
		}
		list->next->prev = list;
		list->next->data = data;
		list->next->type = type;
		list->next->dirty = 1;
		list->next->next = NULL;		
	}

	return original;
}

List* append(List* list, void* data)
{
	return append_t(list, data, 0);
}

int count(List* list)
{
	if(!list)
		return 0;

	int c = 1;

	while(list->next)
	{
		list = list->next;
		c++;
	}

	return c;
}

void* nth(List* list, int n)
{
	assert(list);

	int i;
	for(i=0; i<n; i++)
	{
		list = list->next;
		assert(list);
	}

	return list->data;
}

void* last(List* list)
{
	assert(list);

	while(list->next)
		list = list->next;

	return list->data;
}
