/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line[fd].c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:20:38 by truangsi          #+#    #+#             */
/*   Updated: 2022/11/03 11:20:39 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_temp(char *temp, int fd, int rd)
{
	char	*buff;

	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	temp = (char *) malloc(1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
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
	}
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
	static t_data	line[OPEN_MAX];
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line[fd].temp)
		line[fd].temp = create_temp(NULL, fd, 1);
	if (line[fd].temp == NULL)
		return (NULL);
	i = 0;
	while (line[fd].temp[line[fd].j] != '\n' && line[fd].temp[line[fd].j] != '\0')
	{
		line[fd].j++;
		i++;
	}
	if ((i == 0 && line[fd].temp[line[fd].j] == '\0') || line[fd].temp[0] == '\0')
	{
		free(line[fd].temp);
		line[fd].temp = NULL;
		return (NULL);
	}
	if (line[fd].temp[line[fd].j] == '\n')
		line[fd].j += 1;
	return (get_line(line[fd].temp, line[fd].j, &i, NULL));
}

// int	main(int argc, char **argv)
// int	main(void)
// {
// 	// int	fd = open("/Users/truangsi/Othello42-get_next_line-tester/file/fd_Beyond File", O_RDONLY);
// 	int	fd = open("/Users/truangsi/get_next_line/gnlTester/files/empty", O_RDONLY);
// 	// int fd = open(argv[1], O_RDONLY);
// 	int	rd;
// 	char	*c;

// 	rd = 0;
// 	// c = (char *) malloc(100 * sizeof(char));
// 	if (fd == -1)
// 		printf("Error, cannot open\n");
// 	// if (argc)
// 	// {
// 		// c = get_next_line(fd);
// 		// printf("%s", c);
// 	// 	free(c);
// 	// 		while (c)
// 	// 	{
// 	// 		c = get_next_line(fd);
// 	// 		printf("%s", c);
// 	// 		free(c);
// 	// 	}
// 	// }
// 	// read(fd, &a, 1);
// 	// printf("here:%d", a);
// 	c = get_next_line(1000);
// 	printf("%s", c);
// 	free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);
// 	// free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);
// 	// free(c);
// 	// close(fd);
// 	return (0);
// }
