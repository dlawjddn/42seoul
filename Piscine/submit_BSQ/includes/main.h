/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:52:05 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/06 22:08:13 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

void	add(int *size, char **s);
char	**make_map(int fd, int sum, char *sign);
int		print_map(char **map, int size, char *sign);
int		same_check(char c, char *sign, int n);

#endif
