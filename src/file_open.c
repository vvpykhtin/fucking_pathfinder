#include "pathfinder.h"

bool file_open(char *v) {
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
