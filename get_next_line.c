/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:50:18 by cdoreah           #+#    #+#             */
/*   Updated: 2019/09/16 22:14:06 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int read_file(const int fd, char **b)
{
	char buf[BUFF_SIZE + 1];

	if (read(fd, buf, BUFF_SIZE) > 0)
	{
		*b = ft_strjoin(*b, buf);
		printf("%s", *b);
		return (1);
	}
	return (0);
}


int		get_next_line(const int fd, char **line)
{
	static char *b;
	b = "\0";
	char *stop;

	read_file(fd, &b);

	int i = 0;
	while (b[i] != '\n')
		i++;
	b[i] = '\0';
	*line = ft_strdup(b);
	printf("\nline: %s", *line);
	return (0);
}

int main()
{
	char *line = NULL;
	int i = 0;
	int fd = open("../file", O_RDONLY);
	printf("%d\n", ++i);
	get_next_line(fd, &line);
	printf("\n\n%d\n", ++i);
	get_next_line(fd, &line);
	printf("\n\n%d\n", ++i);
	get_next_line(fd, &line);

	printf("\n");
	return 0;
}