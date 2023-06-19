/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:35:56 by alsaeed           #+#    #+#             */
/*   Updated: 2023/06/14 23:05:45 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strjoint(char *s1, char *s2)
{
	char	*joint;

	joint = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (joint);
}

static char	*ft_read(int fd, char *stash)
{
	char	*buf;
	ssize_t	read_bytes;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		*stash = '\0';
	}
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buf), NULL);
		buf[read_bytes] = '\0';
		stash = strjoint(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, NULL, 0))
		return (NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ret_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
