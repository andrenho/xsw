#include <stdlib.h>
#include "list.h"

List* append(List* list, void* data)
{
	if(!list)
	{
		list = malloc(sizeof(List));
		list->prev = NULL;
		list->next = NULL;
		list->data = data;
	}
	else
	{
		while(list->next)
			list = list->next;

		list->next = malloc(sizeof(List));
		list->next->prev = list;
		list->next->data = data;
		list->next->next = NULL;		
	}

	return list;
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

	return 0;
}
