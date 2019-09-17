/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:50:02 by cdoreah           #+#    #+#             */
/*   Updated: 2019/09/17 22:25:08 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_GET_NEXT_LINE_H
# define GET_NEXT_GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
#include "libft/libft.h"

# define BUFF_SIZE 50

int		get_next_line(const int fd, char **line);

#endif
