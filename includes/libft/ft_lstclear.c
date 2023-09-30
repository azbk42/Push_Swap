/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbreak <azbreak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:57 by azbreak           #+#    #+#             */
/*   Updated: 2023/08/30 16:05:38 by azbreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
    t_list *prev;
    
    current = *lst;
    if (current)
    {
          while(current)
        {
            prev = current;
            del(current->content);
            current = current->next;
            free(prev);
        }
        *lst = NULL;
    }   
}
