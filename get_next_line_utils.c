/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:54:04 by jperras           #+#    #+#             */
/*   Updated: 2022/03/05 09:48:31 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
void	ft_strcpy(char *src, char *dst)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_read(int fd, char *str, int ret, char *buf)
{
	int		j;
	char	*buffer;

	j = 1;
	while (ret > 0 && buf[0] != '\n')
	{
		ft_strcpy(buf, str);
		buffer = malloc(sizeof(char) * (j + 1));
		buffer[0] = '\0';
		ft_strcpy(str, buffer);
		str = 0;
		free(str);
		j++;
		str = malloc(sizeof(char) * (j + 1));
		str[0] = '\0';
		ft_strcpy(buffer, str);
		buffer = 0;
		free(buffer);
		ret = read(fd, buf, 1);
		buf[1] = '\0';
	}
	ret = read(fd, buf, 1);
	buf[1] = '\0';
	free(buffer);
	if (ret > 0)
		return(ft_line(str));
	return (str);
}

char	*ft_line(char *str)
{
	char	*buffer;
	int		i;

	i = 0;
	while (str[i])
		i++;
	buffer = malloc(sizeof(char) * (i + 1));
	ft_strcpy(str, buffer);
	str = 0;
	free(str);
	str = malloc(sizeof(char) * (i + 2));
	ft_strcpy(buffer, str);
	buffer = 0;
	free(buffer);
	str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}
