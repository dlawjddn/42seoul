/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:01:02 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/05/25 12:52:14 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	argc = 1;
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
