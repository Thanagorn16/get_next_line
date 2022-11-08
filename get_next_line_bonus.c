/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:32:25 by truangsi          #+#    #+#             */
/*   Updated: 2022/11/08 14:32:26 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_temp(char *temp, int fd, int rd)
{
	char	*buff;
	int	i;

	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!temp)
	{
		temp = (char *) malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
	}
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		buff[rd] = '\0';
		temp = ft_strjoin(temp, buff);
		i = 0;
		while(buff[i] != '\0')
		{
			if (buff[i] == '\n')
			{
				free(buff);
				return (temp);
			}
			i++;
		}
	}
	free(buff);
	return (temp);
}

char	*get_line(char *temp, int *j, int *i, char *str)
{
	int	e;

	if (temp[*j] == '\n')
		*j += 1;
	if (temp[*j] == '\0' && temp[(*j) - 1] != '\n')
	{
		str = (char *) malloc(sizeof(char) * (*i) + 1);
		if (!str)
			return (NULL);
		str[*i] = '\0';
		(*i)--;
	}
	else
	{
		str = (char *) malloc(sizeof(char) * (*i) + 2);
		if (!str)
			return (NULL);
		str[*i + 1] = '\0';
	}
	e = (*j) - 1;
	while (*i >= 0)
		str[(*i)--] = temp[e--];
	return (str);
}

char	*get_next_line(int fd)
{
	static t_data	line[OPEN_MAX];
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd].temp = create_temp(line[fd].temp, fd, 1);
	if (line[fd].temp == NULL)
		return (NULL);
	i = 0;
	while (line[fd].temp[line[fd].j] != '\n'
		&& line[fd].temp[line[fd].j] != '\0')
	{
		line[fd].j++;
		i++;
	}
	if ((i == 0 && line[fd].temp[line[fd].j] == '\0')
		|| line[fd].temp[0] == '\0')
	{
		free(line[fd].temp);
		line[fd].temp = NULL;
		return (NULL);
	}
	return (get_line(line[fd].temp, &line[fd].j, &i, NULL));
}
