/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:40:33 by sde-mull          #+#    #+#             */
/*   Updated: 2021/11/26 15:54:48 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_backup(char *saved_line)
{
	int		index;
	int		index_2;
	char	*p_line;

	index = 0;
	index_2 = 0;
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
		index++;
	if (saved_line[index] == '\0')
	{
		free(saved_line);
		return (NULL);
	}
	p_line = (char *)malloc(sizeof(char) * (ft_strlen(saved_line) - index + 1));
	if (p_line == 0)
		return (NULL);
	index++;
	while (saved_line[index])
		p_line[index_2++] = saved_line[index++];
	p_line[index_2] = '\0';
	free(saved_line);
	return (p_line);
}

char	*ft_get_line(char *saved_line)
{
	char	*line;
	int		index;

	index = 0;
	if (saved_line[index] == 0)
		return (NULL);
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (line == 0)
		return (NULL);
	index = 0;
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
	{
		line[index] = saved_line[index];
		index++;
	}
	if (saved_line[index] == '\n')
	{
		line[index] = saved_line[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *saved_line)
{
	char	*line;
	int		reader;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == 0)
		return (NULL);
	reader = 1;
	while (!ft_strchr(saved_line, '\n') && reader != 0)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader == -1)
		{
			free(line);
			return (NULL);
		}
		line[reader] = '\0';
		saved_line = ft_strjoin(saved_line, line);
	}
	free(line);
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line[1024];
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	saved_line[fd] = ft_read_save(fd, saved_line[fd]);
	if (saved_line[fd] == 0)
		return (NULL);
	get_line = ft_get_line(saved_line[fd]);
	saved_line[fd] = ft_backup(saved_line[fd]);
	return (get_line);
}
