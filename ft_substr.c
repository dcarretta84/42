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
2	#include <stdio.h>
3	#include <string.h>
4	#include <stddef.h>
5	
6	char *ft_substr(char const *s, unsigned int start, size_t len)
7	{
8	    size_t    x;
9	    size_t  len_s;
10	
11	    if (!s)
12	        return (NULL);
13	    x = 0;
14	    len_s = strlen(s);
15	    if (start > len_s)
16	        return (NULL);
17	    size_t tot = start + len;
18	    if (tot > len_s) 
19	        len = len_s - start;
20	    char    *array = (char *)malloc((len + 1) * sizeof(char));
21	    if (array == NULL)
22	        return (NULL);
23	    while (x < len)
24	    {
25	        array[x] = s[start + x];
26	        x++;
27	    }
28	    array[x] = '\0';
29	    return (array);
30	}
31	
32	int main(void)
33	{
34	    char *s = "www.altamura.it";
35	    unsigned int start = 0;
36	    size_t len = -5;
37	    char *p = ft_substr(s, start, len);
38	    printf("%s\n", p);
39	    free (p);
40	    return (0);
41	}