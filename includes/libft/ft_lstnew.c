/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:47:05 by azbreak           #+#    #+#             */
/*   Updated: 2023/09/30 20:07:13 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list *new;

    new = malloc(sizeof(t_list));
    if (new)
    {
        new->content = content;
        new->next = NULL;
    }
    return (new);
}
