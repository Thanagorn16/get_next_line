/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:01:58 by truangsi          #+#    #+#             */
/*   Updated: 2022/11/03 12:01:59 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		a;
	char	*ptr;

	i = 0;
	a = 0;
	if (!str1)
		return (NULL);
	ptr = (char *) malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ptr)
		return (NULL);
	while (str1[i] != '\0')
	{
		ptr[i] = str1[i];
		i++;
	}
	while (str2[a] != '\0')
	{
		ptr[i] = str2[a];
		i++;
		a++;
	}
	ptr[i] = '\0';
	return (ptr);
}