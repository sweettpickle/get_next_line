/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:50:18 by cdoreah           #+#    #+#             */
/*   Updated: 2019/09/17 22:25:08 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int read_file(const int fd, char **b)
{
	char buf[BUFF_SIZE + 1];
	int ret;

    ft_bzero(buf, BUFF_SIZE + 1);
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
	    buf[ret] = '\0';
		*b = ft_strjoin(*b, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
		return (1);
	}
	if (!ret)
	    return (0);
	return (-1);
}

void get_line(char **b, char **line)
{
    int len;
    int len_b;

    len_b = ft_strlen(*b);
    len = 0;
    while (b[0][len] != '\n' && len_b > 0)
    {
        len++;
        len_b--;
    }
    *line = ft_strncpy(ft_strnew(len), *b, len);
    *b = ft_strsub(*b, len + 1, ft_strlen(*b));
}

int		get_next_line(const int fd, char **line)
{
	static char *b;
	int ret;

	if (!b)
	    b = "\0";
	if ((!(ret = read_file(fd, &b)) && !ft_strcmp(b, "\0")) || !line)
	    return (0);
	if (ret == -1 || fd < 0)
	    return (-1);
    while (!ft_strchr(b, '\n') && ret)
        ret = read_file(fd, &b);
    if (!ft_strchr(b, '\n') && !b)
        return (0);
//    printf("old b: \n%s", b);
    get_line(&b, line);
//    printf("\n\nline: \n%s", *line);
//    printf("\n%d", strcmp(*line, "1234567"));
//    printf("\n\nnew b:\n%s", b);
	return (1);
}

//int main()
//{
//	char *line[400];
//
//	int i = 0;
//	int fd = open("../file4", O_RDONLY);
//	printf("%d\n", ++i);
//	printf("%d!!!", get_next_line(fd, line));
//
////	printf("\n\n%d\n", ++i);
////    printf("%d!!!", get_next_line(fd, line));
////
////	printf("\n\n%d\n", ++i);
////    printf("%d", get_next_line(fd, line));
////
////	printf("\n\n%d\n", ++i);
////    printf("%d", get_next_line(fd, line));
////
////	printf("\n\n%d\n", ++i);
////    printf("%d", get_next_line(fd, line));
////
//	printf("\n");
//	return 0;
//}