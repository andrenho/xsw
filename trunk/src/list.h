#ifndef LIST_H
#define LIST_H

typedef struct List {
	void* data;
	struct List* prev;
	struct List* next;
} List;

List* ladd(List* l, void* data);
int lcount(List* l);
void* ln(List* l, int n);
/* void* llast(List* l); */

#endif
