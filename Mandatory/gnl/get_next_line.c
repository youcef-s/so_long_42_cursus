/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:13:20 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/11/19 20:22:13 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffers)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buffers, '\n') && bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		buff[bytes_read] = '\0';
		buffers = ft_strjoin(buffers, buff);
	}
	return (buffers);
}

char	*get_line(char *buffers)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffers[i])
		return (0);
	while (buffers[i] != '\n' && buffers[i])
		i++;
	if (buffers[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = -1;
	while (buffers[++i] && buffers[i] != '\n')
		line[i] = buffers[i];
	if (buffers[i] == '\n')
	{
		line[i] = buffers[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_buffers(char *buffers)
{
	char	*new_buffers;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (buffers[i] && buffers[i] != '\n')
		i++;
	if (!buffers[i])
	{
		free (buffers);
		return (0);
	}
	len = ft_strlen(buffers) - i;
	new_buffers = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_buffers)
		return (0);
	i++;
	j = 0;
	while (buffers[i])
		new_buffers[j++] = buffers[i++];
	new_buffers[j] = '\0';
	free (buffers);
	return (new_buffers);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffers;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffers = ft_read(fd, buffers);
	if (!buffers)
		return (0);
	line = get_line(buffers);
	buffers = new_buffers(buffers);
	return (line);
}
