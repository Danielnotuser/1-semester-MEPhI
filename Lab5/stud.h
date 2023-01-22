#ifndef STUD_H
#define STUD_H

typedef struct Stud {
	char *name;
	char group[8];
	float mark;
} Stud;

Stud stud_init(char *name, char group[8], float mark);
void stud_print(const Stud*);
void quick_sort(Stud*, int, int (*) (const Stud*, const Stud*));
void shell_sort(Stud*, int, int (*) (const Stud*, const Stud*));
void swap(Stud*, Stud*);
int stud_cmp_name(const Stud*, const Stud*);
int stud_cmp_group(const Stud*, const Stud*);
int stud_cmp_mark(const Stud*, const Stud*);
int stud_cmp_rname(const Stud*, const Stud*);
int stud_cmp_rgroup(const Stud*, const Stud*);
int stud_cmp_rmark(const Stud*, const Stud*);
int read_file(Stud**, char*, int*);
void arr_print(Stud*, int);


#endif
