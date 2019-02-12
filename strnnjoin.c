#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include "libft/includes/libft.h"

char    *ft_strnnjoin(char const *s1, char const *s2, size_t size1, size_t size2)
{
    size_t      i;
    size_t      j;
    char        *a;

    i = 0;
    j = 0;
    size1 = (size1 == 0 ? strlen(s1) : size1);
    size2 = (size2 == 0 ? strlen(s2) : size2);
    if (!s1 || !s2 || !(a = (char*)malloc(size1 + size2 + 1)))
        return (NULL);
    while (i < size1)
    {
        a[i] = s1[i];
        i++;
    }
    while (i < size2)
    {
        a[i] = s2[j];
        i++;
        j++;
    }
    a[i] = '\0';
    return (a);
}
int main() 
{
    char a[] = "12345";
    char b[] = "";
    char *c;
    c = ft_strnnjoin(a, b, 0, 1);
    write(1, c, 6);
    write(1, "\n", 1);
    return 0;
}