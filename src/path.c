#include "pathfinder.h"

static t_path *create_path(int *edges, int size) {
    t_path *path = (t_path *)malloc(sizeof(t_path));

    path->size = size;
    path->edges = edges;
    path->next = NULL;
    return path;
}

void push_path(t_path **path, int *edges, int size) {
    t_path *buf = NULL;

    if (!path)
        return;
    if (*path) {
        buf = *path;
        while (buf->next)
            buf = buf->next;
        buf->next = create_path(edges, size);
    }
    else
        *path = create_path(edges, size);
}

void clean_path(t_path **path)
{
    t_path *buf = NULL;

    if (path && *path) {
        if ((*path)->next) {
            while ((*path)->next) {
                buf = (*path)->next;
                free((*path)->edges);
                free(*path);
                *path = buf;
            }
        }
        else {
            free((*path)->edges);
            free(*path);
            *path = NULL;
        }
    }
}
