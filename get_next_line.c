/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:20:38 by truangsi          #+#    #+#             */
/*   Updated: 2022/11/03 11:20:39 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_join(int rd, int fd, char *temp, char *buff)
{
	int	i;

	i = 0;
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(temp);
			return (NULL);
		}
		buff[rd] = '\0';
		temp = ft_strjoin(temp, buff);
		while (buff[i] != '\0')
		{
			if (buff[i] == '\n')
				return (temp);
			i++;
		}
	}
	return (temp);
}

char	*create_temp(char *temp, int fd, int rd)
{
	char	*buff;

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
	temp = read_and_join(rd, fd, temp, buff);
	free(buff);
	return (temp);
}

char	*get_line(char *temp, int j, int *i, char *str)
{
	int	e;

	if (temp[j] == '\0' && temp[j - 1] != '\n')
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
	e = j - 1;
	while (*i >= 0)
	{
		str[*i] = temp[e];
		(*i)--;
		e--;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_data	line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line.temp = create_temp(line.temp, fd, 1);
	if (line.temp == NULL)
		return (NULL);
	i = 0;
	while (line.temp[line.j] != '\n' && line.temp[line.j] != '\0')
	{
		line.j++;
		i++;
	}
	if ((i == 0 && line.temp[line.j] == '\0') || line.temp[0] == '\0')
	{
		free(line.temp);
		line.temp = NULL;
		return (NULL);
	}
	if (line.temp[line.j] == '\n')
		line.j += 1;
	return (get_line(line.temp, line.j, &i, NULL));
}

// int	main(void)
// {
// 	int	fd = open("mytest.txt", O_RDWR);
// 	char	*gt;
// 	if (fd == -1)
// 		printf("error");

// 	gt = get_next_line(fd);
// 	printf("gnl:%s", gt);
// 	free(gt);
// 	gt = get_next_line(fd);
// 	printf("gnl:%s", gt);
// 	free(gt);
// 	gt = get_next_line(fd);
// 	printf("gnl:%s", gt);
// 	free(gt);
// 	gt = get_next_line(fd);
// 	printf("gnl:%s", gt);
// 	free(gt);
// }