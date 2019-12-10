#include "libmx.h"

static bool compare(char **res,char * s, int len);

char **mx_onlywords(char **arr) {
    char **res = malloc(digits(arr[0]) * sizeof(char *));
    int k = 0;

    for (int i = 0; i < digits(arr[0]); i++) {
        while ((isdigits(arr[k]) || compare(res, arr[k], digits(arr[0])))  && arr[k] != '\0')
            k++;
        res[i] = mx_strnew(mx_strlen(arr[k]));
        if ((!isdigits(arr[k]) && !compare(res, arr[k], digits(arr[0]))) && arr[k] != '\0') {

                res[i] = arr[k];
                k++;
        }
    }
    res[digits(arr[0])] = NULL;
    return res;
}

static bool compare(char **res,char * s, int len)
{
    for (int i = 0; i < len;i++) {
        if (res[i] == NULL)
            return 0;
        if (mx_strcmp(res[i], s) == 0)
            return 1;
    }
    return 0;
}
