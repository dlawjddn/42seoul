/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeong-w <ljeong-w@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:07:19 by ljeong-w          #+#    #+#             */
/*   Updated: 2022/06/01 14:21:24 by ljeong-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_board(int col, int *board)
{
	int	temp;
	int	check;

	check = 0;
	while (check < col)
	{
		temp = board[col] - board[check];
		if (temp < 0)
			temp *= -1;
		if (temp == 0 || col - check == temp)
			return (0);
		check++;
	}
	return (1);
}

void	print_board(int *board)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = board[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	put_queens(int col, int *cnt, int *board)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		*cnt += 1;
		print_board(board);
		return ;
	}
	while (row < 10)
	{
		board[col] = row;
		if (check_board(col, board))
			put_queens(col + 1, cnt, board);
		row++;
	}	
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	cnt;
	int	board[10];

	cnt = 0;
	i = 0;
	while (i < 10)
		board[i++] = 0;
	put_queens(0, &cnt, board);
	return (cnt);
}
