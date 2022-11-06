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
		return (NULL);
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
			temp = NULL;
			return (NULL);
		}
		buff[rd] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	i = 0;
	while (temp[j] != '\n' && temp[j] != '\0') //get a line from the file
	{
		j++;
		i++;
	}
	if (i == 0 && temp[j] == '\0')
	{
		free(buff);
		free(temp);
		temp = NULL;
		return (NULL);
	}
	if (temp[j] == '\n')
		j += 1;
	if (temp[j] == '\0' && temp[j - 1] != '\n')
	{
		str = (char *) malloc(sizeof(char) * i + 1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		i--;
	}
	else
	{
		str = (char *) malloc(sizeof(char) * i + 2);
		if (!str)
			return (NULL);
		str[i + 1] = '\0';
	}
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
// 	int	fd = open("/Users/truangsi/get_line/gnlTester/files/empty", O_RDONLY);
// 	int	rd;
// 	char	*c;

// 	rd = 0;
// 	// c = (char *) malloc(100 * sizeof(char));
// 	// if (fd == -1)
// 	// 	printf("Error, cannot open\n");
// 	c = get_next_line(1000);
// 	printf("%s", c);
// 	free(c);
// 	// c = get_next_line(-1);
// 	// printf("%s", c);
// 	// free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);
// 	// free(c);
// 	// close(fd);
// 	return (0);
// }
