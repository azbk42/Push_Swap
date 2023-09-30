#include "push_swap.h"


void display_error()
{
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}

// error: non integers, bigger than int max, or duplicate.
// parse pour ajouter tous les nombres dans la linked list 1 a 1.
// check si il sont deja dans la linked list, pour eviter doublon, si ya un doublon -> exit
//faire un atoi qui avance tant quil y a des espaces, si il rencontre un truc autre quun espace
// ou un chiffre -> exit(exit failure) 
// penser a stocker lindex, apres avoir ajouter un nombre pour revenir au bon endroit

// t_list *parsing_argument(char *str)
// {
//     int *index;

//     *index = 0;

// }

int atoi_parsing(char *str, int *index)
{
    long result;
    int divid;

    divid = 1; 
    result = 0;
    while (str[*index] == ' ')
        (*index) ++;
    if (str[*index] == '-' || str[*index] == '+')
    {
        if (str[*index] == '-')
            divid = -1;
        (*index) ++;
    }
    if (!ft_isdigit(str[*index]))
        display_error();
    while (ft_isdigit(str[*index]))
    {
        result = (result * 10) + (str[*index] - '0');
        (*index) ++;
    }
    while (str[*index] == ' ')
        (*index) ++;
    if (result > INT_MAX || result < INT_MIN)
        display_error();
    return (result * divid);
}   





