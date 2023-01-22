#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud.h"

Stud stud_init(char *name, char group[8], float mark) {
	Stud s;
	s.name = name;
	memcpy(s.group, group, 8 * sizeof(char));
	s.mark = mark;
	return s;
}

void stud_print(const Stud *s) 
{
	printf("%s, %s, %f\n", s->name, s->group, s->mark);
}

void arr_print(Stud* arr, int len)
{
	for (int i = 0; i < len; i++)
		stud_print(&arr[i]);
}
void swap(Stud *s1, Stud *s2)
{
	Stud p;
	p = (*s1);
	(*s1) = (*s2);
	(*s2) = p; 
}

int stud_cmp_name(const Stud* s1, const Stud* s2) {
	return strcmp(s1->name, s2->name);
}

int stud_cmp_group(const Stud* s1, const Stud* s2) {
	return strcmp(s1->group, s2->group);
}

int stud_cmp_mark(const Stud* s1, const Stud* s2) {
	return s1->mark - s2->mark;
}

int stud_cmp_rname(const Stud* s1, const Stud *s2) {
	return (-1) * strcmp(s1->name, s2->name);
}

int stud_cmp_rgroup(const Stud* s1, const Stud *s2) {
	return (-1) * strcmp(s1->group, s2->group);
}

int stud_cmp_rmark(const Stud* s1, const Stud* s2) {
	return s2->mark - s1->mark;
}
