/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:54:04 by jperras           #+#    #+#             */
/*   Updated: 2022/03/05 17:34:03 by jperras          ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len;
	char	*str3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	str3 = malloc(sizeof(char) * (len + 1));
	if (str3 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		str3[i] = str2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

char	*ft_read(int fd, char *str, int ret, char *buf)
{
	char	*tmp;

	while (ret > 0 && str[ft_strlen(str) - 1] != '\n')
	{
		if (!*str)
			ft_strcpy(buf, str);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
	}
	return (str);
}
