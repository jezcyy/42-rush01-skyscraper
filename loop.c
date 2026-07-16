/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoe <ymoe@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:02:37 by ymoe              #+#    #+#             */
/*   Updated: 2026/06/07 13:02:37 by ymoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recursive_loop(char **grid, int row, int col)
{
	int	i;

	if (grid[0][0] == '1')
		return ;
	if (row == 5)
		return (print_sol(grid));
	if (col == 5)
		return (recursive_loop(grid, row + 1, 1));
	i = 1;
	while (i <= 4)
	{
		if (!is_in_column(grid, row, col, i)
			&& !is_in_row(grid, row, col, i))
		{
			grid[row][col] = i + '0';
			if (is_valid_view(grid, row, col))
				recursive_loop(grid, row, col + 1);
			grid[row][col] = '0';
		}
		i++;
	}
}

void	loop(char **clues)
{
	char	**grid;

	grid = build_grid();
	fill_borders(grid, clues);
	recursive_loop(grid, 1, 1);
	if (grid[0][0] == '0')
	{
		write(1, "no solution\n", 12);
	}
}

int	main(int argc, char **argv)
{
	char	**clues;

	if (argc != 2)
	{
		write(1, "bad argc\n", 9);
		return (0);
	}
	if (!valid_input(argv))
	{
		write(1, "bad params\n", 11);
		return (0);
	}
	clues = parse_input(argv[1]);
	loop(clues);
	return (0);
}
