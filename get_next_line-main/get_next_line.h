/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeong-w <ijeong-w@student.42seoul.kr>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:17:25 by ijeong-w          #+#    #+#             */
/*   Updated: 2022/08/05 16:10:11 by ijeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char		*get_next_line(int fd);
char		*get_line(char	*backup);
char		*backup_next(char	*backup);
char		*read_and_store(int fd, char *backup);

char		*ft_strchr(char *s, int c);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);

#endif
