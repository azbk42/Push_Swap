


int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    return (c);
}
// #include <unistd.h>

// int main()
// {
//     int c;
//     int i = 'A';
//     while (i <= 'Z')
// 		{
// 			c = ft_toupper(i);
// 			write(1, &c, 1);
// 			i++;
// 		}
// }