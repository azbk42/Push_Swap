#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *str;

    str = s;
    i = 0;
    while (i < n)
    {
        if (str[i] == (unsigned char)c)  
            return (void*)(&str[i]);
        i++;
    }
    return (NULL); 
    
}

// #include <stdio.h>

// int main()
// {
//     char *str = "Salut";
//     char letter = 'S';
//     char *result;
//     int n = 2;

//     printf("result real function: \n");
//     printf("%p \n", memchr(str, letter, n));
//     printf("----------------------------\n");
//     printf("result real function: \n");
//     printf("%p \n", ft_memchr(str, letter, n));
// }

