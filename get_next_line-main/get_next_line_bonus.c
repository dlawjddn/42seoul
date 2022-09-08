/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:12:26 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/08/15 14:39:31 by ljeong-w         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*store_buf(char *buf, char *backup)
{
	char	*new_backup;
	int		new_len;

	if (!backup)
	{
		backup = (char *)malloc(sizeof(char));
		backup[0] = '\0';
	}
	if (!backup)
		return (NULL);
	new_len = ft_strlen(buf) + ft_strlen(backup);
	new_backup = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new_backup)
	{
		free(backup);
		return (NULL);
	}
	ft_strlcpy(new_backup, backup, new_len + 1);
	ft_strlcat(new_backup, buf, new_len + 1);
	free(backup);
	return (new_backup);
}

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
			free(backup);
			return (NULL);
		}
		buf[rbytes] = '\0';
		backup = store_buf(buf, backup);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (backup);
}

char	*get_line(char *backup)
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

char	*backup_next(char *backup)
{
	char	*new_backup;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] != '\n')
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i));
	if (!new_backup)
	{
		free(backup);
		return (NULL);
	}
	i++;
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
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
