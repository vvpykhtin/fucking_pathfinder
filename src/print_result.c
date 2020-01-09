#include "pathfinder.h"
#include <stdio.h>

static void print_path(t_path *path, char **names) {
    for (int i = 0; i < path->size; i++) {
        printf("%s", names[path->edges[i]]);
        if (i < path->size - 1)
            printf(" -> ");
        else
            printf("\n");        
    }
}

static void print_val(t_pf **pf, t_path *path) {
    for (int i = 0; i < path->size - 1; i++) {
        printf("%d", pf[path->edges[i]][path->edges[i + 1]].val);     
        if (i < path->size - 2)
            printf(" + ");
        else
            printf(" = ");
    }
}

void print_result(t_pf **pf, char **names, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            for (t_path *p = pf[i][j].path; p; p = p->next) {
                printf("========================================\n");
                printf("Path: %s -> %s\n", names[i], names[j]);
                printf("Route: ");
                print_path(p, names);
                printf("Distance: ");
                if (p->size > 2)
                    print_val(pf, p);
                printf("%d\n", pf[i][j].val);
                printf("========================================\n");
            }
        }
    }
}
