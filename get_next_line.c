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

	// buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	// if (!buff)
	// 	return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!temp)
	{
		// buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
		// if (!buff)
		// 	return (NULL);
		temp = (char *) malloc(sizeof(char) * BUFFER_SIZE);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		// rd = 1;
		// while (rd != 0)
		// {
		// 	rd = read(fd, buff, BUFFER_SIZE);
		// 	buff[rd] = '\0';
		// 	temp = ft_strjoin(temp, buff);
		// 	// printf("temp:%s\n", temp);
		// 	// printf("buff:%s\n", buff);
		// }
	}
	// 	temp = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	// 	if (!temp)
	// 		return (NULL);
	// temp[0] = '\0';
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		temp = ft_strjoin(temp, buff);
		// printf("temp:%s\n", temp);
		// printf("buff:%s\n", buff);
	}
	i = 0;
	while (temp[j] != '\n' && temp[j] != '\0')
	{
		j++;
		i++;
	}
	j += 1;
	str = (char *) malloc(sizeof(char) * i + 1);
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
	// if (buff)
	// 	free(buff);
	free(buff);
	return (str);
}

// int	main(void)
// {
// 	int	fd = open("mytest.txt", O_RDONLY);
// 	int	rd;
// 	char	*c;

// 	// c = (char *) malloc(100 * sizeof(char));
// 	// if (fd == -1)
// 	// 	printf("Error, cannot open\n");
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	// free(c);
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	c = get_next_line(fd);
// 	printf("%s", c);
// // 	rd = read(fd, c, BUFFER_SIZE);
// // 	printf("read1:%s\n", c);
// // 	printf("ret:%d\n", rd);
// // 	puts("------------");
// // 	rd = read(fd, c, BUFFER_SIZE);
// // 	printf("read2:%s\n", c);
// // 	printf("ret:%d\n", rd);
// // 	rd = read(fd, c, BUFFER_SIZE);
// // 	printf("read2:%s\n", c);
// // 	printf("ret:%d\n", rd);
// // 	rd = read(fd, c, BUFFER_SIZE);
// // 	printf("read2:%s\n", c);
// // 	printf("ret:%d\n", rd);
// 	return (0);
// }
