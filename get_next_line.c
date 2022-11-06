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

char	*get_next_line(int fd)
{
	int	rd;
	char	*buff;
	static char	*temp;
	char	*str;
	int	i;
	static int	j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
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
	rd = 1;
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
		// printf("temp:%s\n", temp);
		// printf("buff:%s\n", buff);
	}
	i = 0;
	while (temp[j] != '\n' && temp[j] != '\0') //get a line from the file
	{
		j++;
		i++;
	}
	if (temp[j] == '\0')
		free(temp);
	// printf("here:%d\n", i);
	j += 1;
	str = (char *) malloc(sizeof(char) * i + 2);
	str[i + 1] = '\0';
	if (!str)
		return (NULL);
	int e;
	e = j - 1;
	while (i >= 0)
	{
		str[i] = temp[e];
		i--;
		e--;
	}
	free(buff);
	return (str);
}

// int	main(void)
// {
// 	int	fd = open("mytest.txt", O_RDONLY);
// 	// close(-1);
// 	int	rd;
// 	char	*c;

// 	rd = 0;
// 	c = (char *) malloc(100 * sizeof(char));
// 	printf("fd :%d\n", fd);
// 	close(fd);
// 	printf("fd :%d", fd);
// 	// if (fd == -1)
// 	// 	printf("Error, cannot open\n");
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	free(c);
// 	// c = get_next_line(fd);
// 	// // // printf("%s", c);
// 	// free(c);
// 	// c = get_next_line(fd);
// 	// // // printf("%s", c);
// 	// free(c);
// 	// close(fd);
// 	return (0);
// }
