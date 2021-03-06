#include "pathfinder.h"

static int count(char **arr_of_isl, int size);

bool mx_errorcase_2(char * v) {	
    char * s = mx_file_to_str(v);
    char **arr_of_isl = mx_ss(s, '-', ',', '\n');
    int res = 0;
    int size = (count_lines(s)-1) * 3;

    free(s);
    res = count(arr_of_isl, size);
    if(res - 1!= digits(arr_of_isl[0])) {
        printer("error: invalid number of islands");
        return 0;
    }
    return 1;
}

static int count(char **arr_of_isl, int size) {
    int res = 0;

    for (int i = 1; i < size; i++) {
        if (i != size-1) {
            while(mx_strcmp(arr_of_isl[i], "*") == 0)
                i++;
        }
        if(isdigits(arr_of_isl[i]))
            i++;
        for(int j = i+1; j < size -1; j++) {
            if(mx_strcmp(arr_of_isl[i],arr_of_isl[j]) == 0 ||
             isdigits(arr_of_isl[j])) {
                arr_of_isl[j] = "*";
            }
        }
        res++;
    }
    return res;
}
