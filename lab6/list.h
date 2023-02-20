#ifndef LIST_H
#define LIST_H

typedef struct Elem {
	char chr;
	struct Elem* next;
} Elem;

typedef struct List {
	Elem* head;
} List;

Elem *elem_init();
List *list_init();
void free_list(List**);
int read_str(List**);
void print_str(List*);
void add_prefix(List*, List*);

#endif
