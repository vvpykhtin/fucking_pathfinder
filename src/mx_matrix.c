#include "pathfinder.h"

static int loc(char **arr, char *s);
int **mx_matrix(char *v) {
    char *s = mx_file_to_str(v);
    char **arr = mx_ss(s, '-', ',', '\n');
    int len = digits(arr[0]);
    int **matrix = (int **)malloc(len * sizeof(int*));

    for (int i = 0; i < len; i++) {
        matrix[i] = (int *)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; arr[i] != NULL; i+=3) {
        if (matrix[loc(arr, arr[i])][loc(arr, arr[i+1])] != 0 &&
         matrix[loc(arr, arr[i])][loc(arr, arr[i+1])] > digits(arr[i+2])) {
            matrix[loc(arr, arr[i])][loc(arr, arr[i+1])] = digits(arr[i+2]);
            matrix[loc(arr, arr[i+1])][loc(arr, arr[i])] = digits(arr[i+2]);
        }
         if (matrix[loc(arr, arr[i])][loc(arr, arr[i+1])] == 0) {
            matrix[loc(arr, arr[i])][loc(arr, arr[i+1])] = digits(arr[i+2]);
            matrix[loc(arr, arr[i+1])][loc(arr, arr[i])] = digits(arr[i+2]);
        }
    }
    return matrix;
}

static int loc(char **arr, char *s)
{
    char **isl = mx_onlywords(arr);
    int i = 0;

    while (mx_strcmp(isl[i], s) != 0)
        i++;
    return i;
}
