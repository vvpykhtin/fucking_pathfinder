#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_path {
    int size;
    int *edges;
    struct s_path *next;
}t_path;

typedef struct s_pf {
    int val;
    t_path *path;
}t_pf;

//path.c
void push_path(t_path **path, int *edges, int size);
void clean_path(t_path **path);

//pathfinder.c
t_pf **pathfinder(int **mat, int size);
void clean_pathfinder(t_pf ***pf, int size);

//print_result
void print_result(t_pf **pf, char **names, int size);

//other
void printer(char *c);
int isdigits(char *c);
int mx_isalf(char c);
int digits(char *c);
bool mx_errorcase_2(char * v);
bool mx_errorcase_1(int c , char * v);
int count_lines(char *v);
char **mx_ss(const char *r, char c, char f, char d);
void mx_printline();
bool mx_error(int c, char *v);
int **mx_matrix(char *v);
char **mx_onlywords(char **arr);
bool file_open(char *v);

#endif
