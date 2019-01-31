/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:16:08 by behiraux          #+#    #+#             */
/*   Updated: 2019/01/31 15:21:08 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoinfree(char *s1, char *s2)
{
	char	*s3;
	int		size;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (s1);
	if (!s1 && !s2)
		return (0);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(s3 = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	free(s1);
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

static int		ft_read(int const fd, char **stack)
{
	char	*buff;
	int		ret;

	if (!(buff = (char *)ft_strnew(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*stack = ft_strjoinfree(*stack, buff);
	}
	free(buff);
	return (ret);
}

static char		ft_give_line(char **line, char **stack, char *endline)
{
	*line = ft_strsub(*stack, 0, (ft_strlen(*stack) - ft_strlen(endline)));
	endline = ft_strdup(endline);
	ft_strdel(stack);
	*stack = ft_strdup(endline + 1);
	free(endline);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*stack[1024];
	char		*endline;
	int			ret;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	endline = ft_strchr(stack[fd], '\n');
	while (endline == NULL)
	{
		ret = ft_read(fd, &stack[fd]);
		if (ret == 0)
		{
			if (ft_strlen(stack[fd]) == 0)
				return (0);
			stack[fd] = ft_strjoinfree(stack[fd], "\n");
		}
		if (ret < 0)
			return (-1);
		else
			endline = ft_strchr(stack[fd], '\n');
	}
	ft_give_line(line, &stack[fd], endline);
	return (1);
}
