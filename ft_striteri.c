/*Function name ft_striteri
Prototype void ft_striteri(char *s, void (*f)(unsigned int,
char*));
Turn in files -
Parameters s: The string on which to iterate.
f: The function to apply to each character.
Return value None
External functs. None
Description Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.*/

#include <string.h>
2	#include <stddef.h>
3	#include <stdio.h>
4	#include <stdlib.h>
5	
6	void ft_zero(unsigned int i, char *c)
7	{
8	    if ((i % 2) == 0)
9	    {
10	        *c = 'c';
11	    }
12	    return ;
13	}
14	void ft_striteri(char *s, void (*f)(unsigned int, char*))
15	{
16	    unsigned int i = 0;
17	    if (!s || !f)
18	        return ;
19	    int len_s = strlen(s);
20	    while (i < len_s)
21	    {
22	        f(i, &s[i]);
23	        i++;
24	    }
25	    return ;
26	}
27	
28	int main()
29	{
30	    char s[] = "123ciao a tutti!!!!";
31	    ft_striteri(s,ft_zero);
32	    printf("%s\n", s);
33	    return (0);
34	}