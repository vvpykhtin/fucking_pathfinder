#include "pathfinder.h"

static bool file_open(char *v);
static void printer_line(int i);
static bool error_line(char ** arr, int count_n);
static bool fun(int i, int j, char **arr);

bool mx_errorcase_1(int c , char * v) {
    if (c != 2) { 
        printer("usage: ./pathfinder [filename]"); 
        return 0;
    }
    if (!file_open(v))
        return 0;
    char *s = mx_file_to_str(v);
    int count_n = count_lines(s);
    char **arr= mx_strsplit(s, '\n');
    if (!isdigits(arr[0])) {
        printer("error: line 1 is not valid");
        return 0;
    }
    if (!error_line(arr, count_n))
        return 0;
    return 1;
}

static bool file_open(char *v) {
    int file = open(v, O_RDONLY);
    char buf[1];
    int n = read(file, buf, sizeof(buf));

    if (file < 0) {
        printer("error: file ");
        printer(v);
        printer(" does not exist");
        return 0;
    }
    if (n <= 0) {
        printer("error: file ");
        printer(v);
        printer(" is empty");
        return 0;
    }
    return 1;
}

static void printer_line(int i) {
    printer("error: line "); 
    printer(mx_itoa(i + 1)); 
    printer(" is not valid");
}

static bool fun(int i, int j, char **arr){
    if ((!mx_isalf(arr[i][j])) && ((arr[i][j]) != '-')) {
        printer_line(i);
        return 0;
    }
    if (arr[i][j + 1] == ',') {
        for (int k = j + 2; arr[i][k]; k++) {
            if ((arr[i][k] < 48 || arr[i][k] > 57 )) {
                printer_line(i);
                return 0;
            }
        }
    }
    if (!arr[i][j+2]) {
        printer_line(i);
        return 0;
    }
    return 1;
}

static bool error_line(char ** arr, int count_n) {
    for (int i = 1; i < count_n; i++) {
        if (mx_count_substr(arr[i], "-") != 1 || 
            mx_count_substr(arr[i], ",") != 1) {
                printer_line(i);
                return 0;
            }
            for (int j = 0; arr[i][j] != ','; j++) {
                if(!fun(i,j,arr))
                    return 0;
            }
        if (mx_count_words(arr[i], '-') != 2 || 
           (!mx_isalf(arr[i][mx_get_char_index(arr[i], '-') + 1]))) {
                printer_line(i);
                return 0;
        }
    }
    return 1;
}
