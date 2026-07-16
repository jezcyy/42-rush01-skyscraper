/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border&printsol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachow <yachow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:28:18 by yachow            #+#    #+#             */
/*   Updated: 2026/06/07 20:28:55 by yachow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//print.c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_sol(char **puzzle_board)
{
	int	i;
	int	j;

	i = 1;
	if (puzzle_board[0][0] == '1')
		return ;
	puzzle_board[0][0] = '1';
	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			ft_putchar(puzzle_board[i][j]);
			j++;
			if (j != 5)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}

void	fill_borders(char **grid, char **clues)
{
	int	pos;

	pos = 0;
	while (pos < 4)
	{
		grid[0][pos + 1] = clues[0][pos];
		grid[5][pos + 1] = clues[1][pos];
		grid[pos + 1][0] = clues[2][pos];
		grid[pos + 1][5] = clues[3][pos];
		pos++;
	}
}
// int	main(void)
// {
// 	char	row0[6] = {'0', '0', '0', '0', '0', '0'};
// 	char	row1[6] = {'0', '1', '2', '3', '4', '0'};
// 	char	row2[6] = {'0', '2', '3', '4', '1', '0'};
// 	char	row3[6] = {'0', '3', '4', '1', '2', '0'};
// 	char	row4[6] = {'0', '4', '1', '2', '3', '0'};
// 	char	row5[6] = {'0', '0', '0', '0', '0', '0'};
// 	char	*grid[6];

// 	char	top[4] = {'4', '3', '2', '1'};
// 	char	bottom[4] = {'1', '2', '2', '2'};
// 	char	left[4] = {'4', '3', '2', '1'};
// 	char	right[4] = {'1', '2', '2', '2'};
// 	char	*clues[4];

// 	grid[0] = row0;
// 	grid[1] = row1;
// 	grid[2] = row2;
// 	grid[3] = row3;
// 	grid[4] = row4;
// 	grid[5] = row5;

// 	clues[0] = top;
// 	clues[1] = bottom;
// 	clues[2] = left;
// 	clues[3] = right;

// 	fill_borders(grid, clues);

// 	write(1, "Top first clue: ", 16);
// 	ft_putchar(grid[0][1]);
// 	ft_putchar('\n');

// 	write(1, "Left first clue: ", 17);
// 	ft_putchar(grid[1][0]);
// 	ft_putchar('\n');

// 	write(1, "Right first clue: ", 18);
// 	ft_putchar(grid[1][5]);
// 	ft_putchar('\n');

// 	write(1, "Bottom first clue: ", 19);
// 	ft_putchar(grid[5][1]);
// 	ft_putchar('\n');

// 	write(1, "\nPrinted solution:\n", 19);
// 	print_sol(grid);

// 	write(1, "\nTry printing again:\n", 21);
// 	print_sol(grid);

// 	return (0);
// }
