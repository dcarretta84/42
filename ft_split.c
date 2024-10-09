/*Function name ft_split
Prototype char **ft_split(char const *s, char c);
Turn in files -
Parameters s: The string to be split.
c: The delimiter character.
Return value The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
static char    *ft_strup_rev(const char *s, size_t len)
{
    size_t i = 0;
    char *p = (char *)malloc((len + 1) * sizeof(char));
    if (!p)
        return (NULL);
    while (i < len)
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

static size_t  ft_counter(char const *s, char c)
{
    size_t count = 0;
    int flag = 0;
    
    while (*s)
    {
        if (*s != c && flag == 0)
        {
            count++;
            flag = 1;
        }
        if (*s == c)
            flag = 0;
       s++;
    }
    return (count);
}

char    **ft_split(char const *s, char c)
{
    if (!s)
        return (NULL);

    size_t word = ft_counter(s, c);
    char **lines= (char **)malloc(word * sizeof(char *));
    if (!lines)
        return (NULL);
    
    size_t i = 0;
    size_t y = 0;
    while (*s)
    {
        if(*s != c )
        {
            const char *start = s;
            size_t len = 0;
            while (*s && *s != c)
            {
                len++;
                s++;
            }
            lines[i] = ft_strup_rev(start, len);
            if (!lines[i])
            {
                while (y < i)
                {
                    free(lines[y]);
                    y++;
                }
                free(lines);
                return (NULL);
            }
            i++;
        }
        else
        {
             s++;
        }
           
    }
    lines[i] = NULL;
    return (lines);
}

int main(void)
{
    char *string = "ciao mappamondo bello";
    char c = ' ';
    char **res = ft_split(string, c);
    return (0);
}

