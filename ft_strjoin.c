/*Function name ft_strjoin
Prototype char *ft_strjoin(char const *s1, char const *s2);
Turn in files -
Parameters s1: The prefix string.
s2: The suffix string.
Return value The new string.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len_s1;
    size_t  len_s2;
    size_t  tot_len;
    size_t  x;
    size_t  y;

    x = 0;
    y = 0;
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    tot_len = len_s1 + len_s2 + 1;
    char *array = (char *)malloc(tot_len * (sizeof(char)));
    if (array == NULL)
        return (NULL);

    while (s1[x] != '\0')
    {
        array[x] = s1[x];
        x++;
    }
    while (s2[y] != '\0')
    {
        array[y + x] = s2[y];
        y++;
    }
    array[x + y] = '\0';
    return (array);
}
int main(void)
{
    char *s1 = "ciao mondo";
    char *s2 = ", che mi sembri triste!";
    char  *res = ft_strjoin(s1, s2);
    printf("%s\n", res);
    return (0);
}