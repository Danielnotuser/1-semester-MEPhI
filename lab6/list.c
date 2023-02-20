#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define VOWELS "AEIOUYaeiouy"
#define DELIM " \t"

Elem *elem_init() {
	return (Elem*) calloc(1, sizeof(Elem));	
}

List *list_init() {
	return (List*) calloc(1, sizeof(List));	
}

void free_list(List **str)
{
	Elem *symb, *symb_next;
	symb = (*str)->head;
	while (symb)
	{
		symb_next = symb->next;
		free(symb);
		symb = symb_next;
	}
	free(*str);
}

int read_str(List **str_init)
{
	char chr = getchar();
	if (chr == -1) return -1;
	if (chr == '\n') 
	{
		(*str_init) = NULL;
		return 0;
	} 
	List *str = list_init();
	Elem *symb_prev = NULL;
	Elem *symb = elem_init();
	while ((chr != '\n') && (chr != -1))
	{
		symb->chr = chr;
		if (!symb_prev) str->head = symb;
		else symb_prev->next = symb;
		symb_prev = symb;
		symb = elem_init();
		chr = getchar();
	}
	symb_prev->next = NULL;
	free(symb);
	(*str_init) = str;
	return 0;
}

void print_str(List *str)
{
	Elem *pos;
	pos = str->head;
	printf("\"");
	while (pos)
	{
		printf("%c", pos->chr);
		pos = pos->next;
	}
	printf("\"\n");
}

void insert_str(Elem* symb_first, Elem *symb_last, List *pref, List *str)
{
	Elem *symb_prev = elem_init();
	Elem *symb_next = elem_init();
	if (!symb_first) str->head = symb_prev;
	else symb_first->next = symb_prev;
	Elem *pref_symb;
	pref_symb = pref->head;
	symb_prev->chr = pref_symb->chr;
	pref_symb = pref_symb->next;
	while (pref_symb)
	{
		symb_next->chr = pref_symb->chr;
		symb_prev->next = symb_next;
		symb_prev = symb_next;
		pref_symb = pref_symb->next;
		symb_next = elem_init();
	}	
	symb_prev->next = symb_last;
	free(symb_next);
}

void add_prefix(List *pref, List *str) 
{
	Elem *symb_prev;
	Elem *last = NULL;
	Elem *symb = NULL;
	symb_prev = str->head;
	while (symb_prev && strchr(DELIM, symb_prev->chr))
	{
		symb = symb_prev->next;
		free(symb_prev);
		symb_prev = symb;
	}
	symb = symb_prev;
	str->head = symb;
	symb_prev = symb;
	while (symb)
	{
		if (!strchr(DELIM, symb->chr))
		{
			if (!strchr(VOWELS, symb->chr) && (symb == str->head || strchr(DELIM, symb_prev->chr)))
			{
				if (symb == str->head)
				{
					insert_str(NULL, symb, pref, str);
				}
				else
				{
					insert_str(symb_prev, symb, pref, str);
				} 
			}
			else if (symb_prev != symb)
			{
				symb_prev->next = symb;	
			}
			if (symb->next == NULL || (symb->next && strchr(DELIM, (symb->next)->chr)))
			{
				last = symb;
			}
		}
		else if (symb->next != NULL && strchr(DELIM, symb->chr) && !strchr(DELIM, (symb->next)->chr))
		{
			if (last) 
				last->next = symb;
		}
		else 
		{
			symb_prev = symb;
			symb = symb->next;
			free(symb_prev);
			continue;
		}
		symb_prev = symb;
		symb = symb->next;
	}
	if (last) last->next = NULL;
}
