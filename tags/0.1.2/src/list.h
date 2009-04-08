#ifndef LIST_H
#define LIST_H

typedef struct List {
	struct List* prev;
	void* data;
	int type;
	struct List* next;
} List;

List* append(List* list, void* data);
int count(List* list);

#endif
