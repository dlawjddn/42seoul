/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeong-w <ijeong-w@student.42seoul.kr>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:17:25 by ijeong-w          #+#    #+#             */
/*   Updated: 2022/08/05 16:10:11 by ijeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_store(int fd, char *backup)
{
	char	*buf;
	int		rbytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rbytes = 1;
	while (rbytes != 0)
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rbytes] = '\0';
		backup = ft_strjoin(backup, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (backup);
}

char	*get_line(char	*backup)
{
	char	*buf;
	int		i;

	i = 0;
	if (!backup[0])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		buf[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	return (buf);
}

char	*backup_next(char	*backup)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!buf)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		buf[j++] = backup[i++];
	buf[j] = '\0';
	free(backup);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup[256];

	if (fd < 0 || fd + 1 > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = read_and_store(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	buf = get_line(backup[fd]);
	backup[fd] = backup_next(backup[fd]);
	return (buf);
}
