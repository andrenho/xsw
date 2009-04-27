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
	List* ll = l;

	while(n >= 0)
	{
		if(!ll)
			return NULL;
		ll = ll->next;
		n--;
	}

	return ll->data;
}

int main()
{
	List* l = NULL;
	l = ladd(l, "Teste 1");
	l = ladd(l, "Teste 2");
	printf("%d\n", lcount(l));
	printf("%s\n", ln(l, 1));
	return 0;
}
