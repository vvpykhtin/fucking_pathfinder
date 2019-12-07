#include "libmx.h"

bool mx_errorcase_1(int c , char * v)
{
  if(c != 2) { printer("usage: ./pathfinder [filename]"); return 0;}
  else {
    int file = open(v, O_RDONLY);
    char buf[1];
    if(file < 0) {
      printer("error: file ");
      printer(v);
      printer(" doesn't exist");
      return 0;
    }
    else {
      int n = read(file, buf, sizeof(buf));
      if (n <= 0) {
	printer("error: file ");
	printer(v);
	printer(" is empty");
	return 0;
      }
      else {
	char * s = mx_file_to_str(v);
	char ** arr = NULL;
	int count_n = count_lines(s);

	arr = mx_strsplit(s, '\n');
	if(!isdigits(arr[0]))
	  {
	    printer("error: line 1 isn't valid");
	    return 0;
	  }
	for(int i = 1; i < count_n; i++)
	  {
	    if(mx_count_substr(arr[i], "-") != 1 || mx_count_substr(arr[i], ",") != 1)
	      {
		printer("error: line "); printer(mx_itoa(i + 1)); printer(" isn't valid");
		return 0;
	      }
	    for(int j = 0; arr[i][j] != ','; j++)
	      {
		if((!mx_isalf(arr[i][j])) && ((arr[i][j]) != '-'))
		  {
		    printer("error: line "); printer(mx_itoa(i + 1)); printer(" isn't valid");
		    return 0;
		  }
		if(arr[i][j + 1] == ',')
		  {
		    for(int k = j + 2; arr[i][k]; k++) {
		      if((arr[i][k] < 48 || arr[i][k] > 57 ))
			{
			  printer("error: line "); printer(mx_itoa(i + 1)); printer(" isn't valid");
			  return 0;
			}
		    }
		  }
		if(!arr[i][j+2]) {
		  printer("error: line "); printer(mx_itoa(i + 1)); printer(" isn't valid");
		  return 0;
		}
	      }
	    if(mx_count_words(arr[i], '-') != 2 || (!mx_isalf(arr[i][mx_get_char_index(arr[i], '-') + 1])))
	      {
		printer("error: line "); printer(mx_itoa(i + 1)); printer(" isn't valid");
		return 0;
	      }
	    
	  }

      }
    }
  }
  return 1;
}
