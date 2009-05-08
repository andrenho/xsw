#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"

List* ladd(List* l, void* data)
{
	if(!l)
	{
		l = malloc(sizeof(List));
		if(!l)
		{
			fprintf(stderr, "Oops... we're out of memory!\n");
			exit(1);
		}
		l->next = l->prev = NULL;
		l->data = data;
		return l;
	}
	else
	{
		List* ll = l;
		while(ll->next)
			ll = ll->next;

		List* ln = malloc(sizeof(List));
		ln->prev = ll;
		ln->data = data;
		ln->next = NULL;
		ll->next = ln;
		return l;
	}

}

List* linsert(List* l, int n, void* data)
{
	List* ll = l;

	if(!l)
	{
		if(n == 0)
			return ladd(l, data);
		else
			abort();
	}

	int i;
	for(i=0; i<n; i++)
	{
		assert(l);
		l = l->next;
	}

	if(!l) // last record
	{
		ladd(ll, data);
	}
	else
	{
		List* prev = l->prev;
		List* next = l;
		List* _new = malloc(sizeof(List));
		if(prev)
			prev->next = _new;
		if(next)
			next->prev = _new;
		_new->prev = prev;
		_new->next = next;
		_new->data = data;
		if(!_new->prev)
			return _new;
	}
	return ll;
}

int lcount(List* l)
{
	int i = 0;

	while(l)
	{
		i++;
		l = l->next;
	}

	return i;
}

void* ln(List* l, int n)
{
	int i;
	List* ll = l;

	for(i=0; i<n; i++)
	{
		ll = ll->next;
		assert(ll);
	}

	return ll->data;
}
