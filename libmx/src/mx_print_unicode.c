#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char str[5] = {0};
    if (c <= 0x7F) { // ascii
        str[0] = (char) c;
    }
    else if (c <= 0x07FF) { // 2-bute unicode
        str[0] = (char) (((c >> 6)  & 0x1F) | 0xC0);
        str[1] = (char) (((c >> 0)  & 0x3F) | 0x80);
    }
    else if (c <= 0xFFFF) { // 3-byte unicode
        str[0] = (char) (((c >> 12) & 0x0F) | 0xE0);
        str[1] = (char) (((c >> 6)  & 0x3F) | 0x80);
        str[2] = (char) (((c >> 0)  & 0x3F) | 0x80);
    }
    else if (c<0x10FFFF) {
        str[0] = (char) (((c >> 18) & 0x07) | 0xF0);
        str[1] = (char) (((c >> 12) & 0x3F) | 0x80);
        str[2] = (char) (((c >> 6)  & 0x3F) | 0x80);
        str[3] = (char) (((c >> 0)  & 0x3F) | 0x80);
    }
    write(1, str, mx_strlen(str));
}
