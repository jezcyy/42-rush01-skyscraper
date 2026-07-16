/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachow <yachow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:35:41 by yachow            #+#    #+#             */
/*   Updated: 2026/06/07 19:35:41 by yachow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_correct_left_view(char **grid, int row)
{
	int	col;
	int	max;
	int	count;
	int	height;

	col = 1;
	max = 0;
	count = 0;
	while (col <= 4)
	{
		height = grid[row][col] - '0';
		if (height > max)
		{
			max = height;
			count++;
		}
		col++;
	}
	return (count == grid[row][0] - '0');
}

int	is_correct_right_view(char **grid, int row)
{
	int	col;
	int	max;
	int	count;
	int	height;

	col = 4;
	max = 0;
	count = 0;
	while (col >= 1)
	{
		height = grid[row][col] - '0';
		if (height > max)
		{
			max = height;
			count++;
		}
		col--;
	}
	return (count == grid[row][5] - '0');
}

int	is_correct_top_view(char **grid, int col)
{
	int	row;
	int	max;
	int	count;
	int	height;

	row = 1;
	max = 0;
	count = 0;
	while (row <= 4)
	{
		height = grid[row][col] - '0';
		if (height > max)
		{
			max = height;
			count++;
		}
		row++;
	}
	return (count == grid[0][col] - '0');
}

int	is_correct_bottom_view(char **grid, int col)
{
	int	row;
	int	max;
	int	count;
	int	height;

	row = 4;
	max = 0;
	count = 0;
	while (row >= 1)
	{
		height = grid[row][col] - '0';
		if (height > max)
		{
			max = height;
			count++;
		}
		row--;
	}
	return (count == grid[5][col] - '0');
}

int	is_valid_view(char **grid, int row, int col)
{
	if (col == 4 && !is_correct_left_view(grid, row))
		return (0);
	if (col == 4 && !is_correct_right_view(grid, row))
		return (0);
	if (row == 4 && !is_correct_top_view(grid, col))
		return (0);
	if (row == 4 && !is_correct_bottom_view(grid, col))
		return (0);
	return (1);
}
