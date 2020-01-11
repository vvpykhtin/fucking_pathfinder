#include "pathfinder.h"

static t_pf **create_pf(int **mat, int size) {
    t_pf **pf = (t_pf **)malloc(size * sizeof(t_pf *));
    int *edges = NULL;

    for (int i = 0; i < size; i++)
    {
        pf[i] = (t_pf *)malloc(size * sizeof(t_pf));
        for (int j = 0; j < size; j++)
        {
            pf[i][j].val = mat[i][j];
            pf[i][j].path = NULL; 
            if (pf[i][j].val)
            {
                edges = (int *)malloc(2 * sizeof(int));
                edges[0] = i;
                edges[1] = j;
                push_path(&pf[i][j].path, edges, 2);
            }         
        }
    }
    return pf;
}

static void add_path(t_pf **pf, int i, int k, int j)
{
    int *buf = NULL;

    for (t_path *p = pf[i][k].path; p; p = p->next)
    {
        for (t_path *p2 = pf[k][j].path; p2; p2 = p2->next)
        {
            buf = (int *)malloc((p->size + p2->size - 1)  * sizeof(int));
            for (int i = 0; i < p->size; i++)
                buf[i] = p->edges[i];
            for (int i = 0; i < p2->size; i++)
                buf[i + p->size - 1] = p2->edges[i];
            push_path(&pf[i][j].path, buf, p->size + p2->size - 1);
        }
    }
}

t_pf **pathfinder(int **mat, int size) {
    t_pf **pf = create_pf(mat, size);

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (pf[i][k].val && pf[k][j].val && i != j) {
                    if (pf[i][j].val >= pf[i][k].val + pf[k][j].val || !pf[i][j].val) {
                        if (pf[i][j].val > pf[i][k].val + pf[k][j].val || !pf[i][j].val) {
                            pf[i][j].val = pf[i][k].val + pf[k][j].val;
                            clean_path(&pf[i][j].path);
                        }
                        add_path(pf, i, k, j);
                    }
                }
            }
        }
    }
    return pf;
}

void clean_pathfinder(t_pf ***pf, int size)
{
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
                clean_path(&(*pf)[i][j].path);
        }
        free((*pf)[i]);
    }
    free(*pf);
    *pf = NULL;
}
