#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

// MY PACK
void printer(char *c);
int isdigits(char *c);
int mx_isalf(char c);
int digits(char *c);
bool mx_errorcase_2(char * v);
bool mx_errorcase_1(int c , char * v);
int count_lines(char *v);
char **mx_ss(const char *r, char c, char f, char d);
void mx_printline();
void mx_pathfinder(char *v);
bool mx_error(int c, char *v);
int **mx_matrix(char *v);
char **mx_onlywords(char **arr);

#endif
