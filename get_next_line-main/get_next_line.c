/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeong-w <ijeong-w@student.42seoul.kr>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:17:25 by ijeong-w          #+#    #+#             */
/*   Updated: 2022/08/05 16:10:11 by ijeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		rbytes = read(fd, buf, BUFFER_SIZE); //read 는 -1 또는 0 이상의 값을 반환 -1: 에러, 0 이상 : 읽어들인 바이트 수
		if (rbytes == -1) // 읽어들이지 못한 경우, 에러
		{
			free(buf);
			return (NULL);
		}
		buf[rbytes] = '\0';
		backup = ft_strjoin(backup, buf); // buf에 저장된 문자열 복사
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
	if (!backup[0]) // backup에 값이 없다면 (null)
		return (NULL);
	while (backup[i] && backup[i] != '\n') // backup이 존재하고 줄바꿈이 아닐 때까지의 길이
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 2)); //  2 = "\n" + null
	if (!buf)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n') // buf에 복사 ("\n", '\0' 제외)
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
	while (backup[i] && backup[i] != '\n') //개행문자 전까지의 길이 확인
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
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_and_store(fd, backup);
	if (!backup)
		return (NULL);
	buf = get_line(backup);
	backup = backup_next(backup);
	return (buf);
}
