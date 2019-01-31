/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:01:43 by behiraux          #+#    #+#             */
/*   Updated: 2019/01/31 15:32:11 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = size;
	if (!(s = (char *)malloc(sizeof(*s) * (size + 1))))
		return (NULL);
	size = 0;
	while (size < i)
	{
		s[size] = '\0';
		size++;
	}
	s[size] = '\0';
	return (s);
}
