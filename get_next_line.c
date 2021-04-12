/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:27:08 by taejkim           #+#    #+#             */
/*   Updated: 2021/04/12 19:24:07 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_ing(char **line, char **backup, char **buf, char *nl)
{
	

}

int		read_end(char **line, char **backup, char **buf)
{

}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	char		*nl;
	int			readsize;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 )
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readsize = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (readsize = -1)
		{
			free(buf);
			return (-1);
		}
		buf[readsize] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (nl = ft_strchr(backup[fd], '\n'))
			return (read_ing(line, &backup[fd], &buf, nl));
	}
	return (read_end(line, &backup[fd], &buf));
}


// ----------------------------------------------------
#include <stdio.h>
#include <fcntl.h>
int		main()
{
	char	*line;
	int		ret;
	int		fd;

	line = 0;
	fd = open("./test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// 이부분 왜 &line으로 printf함?
		printf("%s\n", &line);
		free(line);
	}
	printf("%s\n", &line);
	free(line);
	return (1);
}
