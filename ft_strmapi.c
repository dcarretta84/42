
/*Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
Turn in files -
Parameters s: The string on which to iterate.
f: The function to apply to each character.
Return value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
External functs. malloc
Description Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f*/
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char ft_zero(unsigned int i, char c)
{
    while ((i % 2) == 0)
    {
        c = '0';
    }
    return (c);
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i = 0;
    char *p;
    if (!s || !f)
        return (NULL);
    int len_s = strlen(s);
    p = (char *)malloc((len_s + 1) * sizeof(char));
    if (p == NULL)
    {
        return (NULL);
    }
    while (i < len_s)
    {
        p[i] = f(i, s[i]);
        i++;
    }
    p[i] = '\0';
    return (p);
}

int main()
{
    char *s = "123ciao a tutti!!!!";
    char *res = ft_strmapi(s,ft_zero);
    printf("%s\n", res);
    free (res);
    return (0);
}