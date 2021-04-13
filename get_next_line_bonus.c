/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:27:08 by taejkim           #+#    #+#             */
/*   Updated: 2021/04/13 15:55:43 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		read_ing(char **line, char **backup, char *nl)
{
	char	*tmp;

	(*nl) = 0;
	(*line) = ft_strdup(*backup);
	if (*(nl + 1) == 0)
		ft_free(backup);
	else
	{
		tmp = ft_strdup(nl + 1);
		ft_free(backup);
		(*backup) = tmp;
	}
	return (1);
}

int		read_end(char **line, char **backup)
{
	char	*nl;

	if (*backup)
	{
		if ((nl = ft_strchr(*backup, '\n')))
			return (read_ing(line, backup, nl));
		(*line) = ft_strdup(*backup);
		ft_free(backup);
		return (0);
	}
	(*line) = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	char		*nl;
	int			readsize;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readsize = read(fd, buf, BUFFER_SIZE)))
	{
		if (readsize == -1)
		{
			ft_free(&buf);
			return (-1);
		}
		buf[readsize] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((nl = ft_strchr(backup[fd], '\n')))
			break ;
	}
	ft_free(&buf);
	if (readsize == 0)
		return (read_end(line, &backup[fd]));
	return (read_ing(line, &backup[fd], nl));
}
