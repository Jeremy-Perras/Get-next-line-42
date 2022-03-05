/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:34:26 by jperras           #+#    #+#             */
/*   Updated: 2022/03/05 09:49:00 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int			ret = 0;
	//char		buf[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*str;
	char		*b;
	static char c[BUFFER_SIZE / BUFFER_SIZE + 1];

	str = malloc(sizeof(char) * (BUFFER_SIZE / BUFFER_SIZE + 1));
	*str = 0;
	if (str == NULL)
		return (NULL);
	if (ret == 0)
	{
		ret = read(fd, c, 1);
		c[1] = '\0';	
	}
	//ret = read(fd, buf, 1);
	//buf[1] = '\0';
	if (ret > 0 && c[0] != '\0')
		b = ft_read(fd, str, ret, c);
	else
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (b);
}
/*
#include <stdio.h>
int main()
{
	int	fd;
	fd = open("fd_Basic Input",O_RDONLY);
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
