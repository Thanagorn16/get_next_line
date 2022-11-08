/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:48 by truangsi          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:50 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		a;
	char	*ptr;

	i = 0;
	a = 0;
	if (str2[0] == '\0')
		return (str1);
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
	free(str1);
	return (ptr);
}
