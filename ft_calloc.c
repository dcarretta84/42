 
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void    *calloc(size_t nmemb, size_t size)
{
    size_t  total;
    void    *ptr;

    total = nmemb * size;
    ptr = malloc(total);
    if (ptr == NULL)
        return (NULL);
    else
        ft_memset(ptr, 0, strlen(ptr));
    return (ptr);
}