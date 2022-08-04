/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:55:49 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/06 22:34:38 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MAP_H
# define PRINT_MAP_H

# include "struct.h"

int	find_min(int **dp, int i, int j);
int	find_max(int a, int b);
int	**set_int_map(t_location map_size);

#endif
