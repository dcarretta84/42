/*Function name ft_strtrim
Prototype char *ft_strtrim(char const *s1, char const *set);
Turn in files -
Parameters s1: The string to be trimmed.
set: The reference set of characters to trim.
Return value The trimmed string.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char *ft_strtrim(char const *s1, char const *set)
{
    //Return if the string is NULL
    if (s1 == NULL || set == NULL)
        return (NULL);
    size_t  x;
    size_t  y;

    x = 0;
    y = x + 1;
    
    //Find the caracter pointer start
    char *start_p = strchr(s1, car);
    //Return if the caracter searched is not present
    if (start_p == NULL)
        return (NULL);
    //Find the caracter pointer end
    char * end_p = strrchr(s1, car);
    //Get number of bytes to allocate
    size_t len_array = end_p - start_p;
    char  *array = (char *)malloc((len_array) *(sizeof(char)));
    if (array == NULL)
      return(NULL);

    while (x < len_array - 1)
    {
      array[x] = start_p[y];
      y++;
      x++;
    }
    array[x] = '\0';
    return (array);
}

int main()
{
  char *str = "www";
  char c = '\0';
  char *set = &c;
  char  *res = ft_strtrim(str, set);
  printf("%s\n", res);
  return (0);
}