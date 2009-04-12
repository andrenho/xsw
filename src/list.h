#ifndef LIST_H
#define LIST_H

typedef struct List {
	struct List* prev;
	void* data;
	int type;
	int dirty;
	struct List* next;
} List;

List* append(List* list, void* data);
List* append_t(List* list, void* data, int type);
int count(List* list);
void* nth(List* list, int n);

#endif
