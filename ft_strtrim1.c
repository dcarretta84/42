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
    y = 0;
    char car = *set;
    size_t len = strlen(s1);
    while (s1[x] != '\0')
    {
        if (s1[x] == car)
            y++;
        x++;
    }
    size_t len_array = len - y + 1;
    char    *array = (char *)malloc(len_array *(sizeof(char)));
    if (array == NULL)
        return (NULL);
        
    x = 0;
    y = 0;
    while (s1[x] != '\0' && y < len_array - 1)
    {
        if (s1[x] == car)
            x++;
        else
        {
          array[y] = s1[x];
          x++;
          y++;
        }
    }
    array[y] = '\0';
    return(array);
    
}

int main()
{
  char *str = "ciao tanti bambina saluta";
  char c = 'a';
  char *set = &c;
  char  *res = ft_strtrim(str, set);
  printf("%s\n", res);
  return (0);
}