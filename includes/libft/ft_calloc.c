/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbreak <azbreak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:00:30 by azbreak           #+#    #+#             */
/*   Updated: 2023/05/24 19:50:05 by azbreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;

	if (size > 0 && (count > ((size_t)-1 / size)))
		return (NULL);
	tab = malloc(count * size * sizeof(char));
	if (!tab)
		return (NULL);
	ft_bzero(tab, (size * count));
	return (tab);
}
