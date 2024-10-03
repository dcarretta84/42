/*Prototype char *ft_substr(char const *s, unsigned int start,
size_t len);
Turn in files -
Parameters s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
Return value The substring.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    x;
    size_t  len_s;

    x = 0;
    len_s = strlen(s);
    if (start >= len_s)
        return (NULL);
    if (start + len > len_s) 
        len = len_s - start;
    char    *array = (char *)malloc((len + 1) * sizeof(char));
    if (array == NULL)
        return (NULL);
    while (x < len)
    {
        array[x] = s[start + x];
        x++;
    }
    array[x] = '\0';
    return (array);
}

int main(void)
{
    char *s = "il mondo e' blue";
    unsigned int start = 3;
    size_t len = 19;
    char *p = ft_substr(s, start, len);
    printf("%s\n", p);
    free (p);
    return (0);
}