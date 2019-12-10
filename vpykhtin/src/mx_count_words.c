#include"libmx.h"
int mx_count_words(const char *str, char c) {
    int i = 0;
    int count = 0;

    if(!str)
        return -1;
    while(str[i + 1] != '\0') {
        if(str[i] == c) {
            while(str[i] == c)
                i++;
        }
        if(str[i] == '\0') 
            return count;
        while(str[i] != c) {
	          i++;
	          if(str[i] == '\0') 
                return count + 1;
        }
        count++;
    }
    return count;
}
