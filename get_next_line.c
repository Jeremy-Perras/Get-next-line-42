/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:34:26 by jperras           #+#    #+#             */
/*   Updated: 2022/03/05 17:29:55 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	ret;
	char		*str;
	//char		*b;
	static char	c[BUFFER_SIZE / BUFFER_SIZE + 1];

	//b = NULL;
	str = malloc(sizeof(char) * (BUFFER_SIZE / BUFFER_SIZE + 1));
	str[0] = '\0';
	//if (str == NULL)
	//	return (NULL);
	if (ret == 0)
	{
		ret = read(fd, c, 1);
		c[ret] = '\0';
	}
	if (ret > 0 && c[0] != '\0')
	{
		str = ft_read(fd, str, ret, c);
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	int	fd;
	fd = open("fd_Empty Lines",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}*/
