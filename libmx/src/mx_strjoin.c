#include"libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
  if(!s1 && !s2) return NULL;
  if(!s1) return (char *)s2;
  if(!s2) return (char *)s1;
  int s1l = mx_strlen(s1);
  int s2l= mx_strlen(s2);
  int j = 0;
  char *result = malloc(s1l+s2l);
  for(int i = 0; i < s1l; i++) {
    result[i] = s1[i];
  }
  for(int i = s1l; i < s1l+s2l;i++)
    {
      result[i] = s2[j]; j++;
    }
    result[s1l+s2l] = '\0';
  return result; 
}
