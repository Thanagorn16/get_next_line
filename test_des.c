#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// void	do_static()
// {
// 	int	n = 1;
// 	static int	sv = 1;
// 	printf("n = %d, sv = %d\n", n , sv);
// 	n++;
// 	sv++;
// }

// int	main(void)
// {
// 	do_static();
// 	for (int i = 0; i < 5; i++)
// 		do_static();
// 	do_static();
// 	return (0);
// }
// int	main(void)
// {
// 	int	fd = open("mytest.txt", O_RDONLY);
// 	int	rd;
// 	char	*c;

// 	c = (char *) malloc(100 * sizeof(char));
// 	if (fd == -1)
// 		printf("Error, cannot open\n");
// 	else
// 		printf("return:%d\n", fd);
// 	rd = read(fd, c, BUFFER_SIZE);


// 	printf("read 1:%s\n", c);
// 	rd = read(fd, c, BUFFER_SIZE);
// 	// printf("read return:%d\n", rd);
// 	printf("read 2:%s\n", c);
// 	return (0);
// }
