
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    while (i >= 0)
    {
        if (s[i] == (char)c)
            return ((char *) &s[i]);
        i--;
    }
    return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "Salutl";
//     char *test;

//     printf("result real fonction: \n");
//     test = strrchr(str, 'l');
//     printf("%s \n", test);

//     printf("----------------------\n");

//     char *str1 = "Salutl";
//     char *test1;

//     printf("result mine fonction: \n");
//     test1 = ft_strrchr(str1, 'l');
//     printf("%s \n", test1);
// }