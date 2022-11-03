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

	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		printf("rd:%d\n", rd);
		printf("%s\n", buff);
	}
	// printf("%d\n", rd);
	return (buff);
}

int	main(void)
{
	int	fd = open("mytest.txt", O_RDONLY);
	int	rd;
	char	*c;

	// c = (char *) malloc(100 * sizeof(char));
	// if (fd == -1)
	// 	printf("Error, cannot open\n");
	get_next_line(fd);
// 	rd = read(fd, c, BUFFER_SIZE);
// 	printf("read1:%s\n", c);
// 	printf("ret:%d\n", rd);
// 	puts("------------");
// 	rd = read(fd, c, BUFFER_SIZE);
// 	printf("read2:%s\n", c);
// 	printf("ret:%d\n", rd);
// 	rd = read(fd, c, BUFFER_SIZE);
// 	printf("read2:%s\n", c);
// 	printf("ret:%d\n", rd);
// 	rd = read(fd, c, BUFFER_SIZE);
// 	printf("read2:%s\n", c);
// 	printf("ret:%d\n", rd);
	return (0);
}
