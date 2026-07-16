/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoe <ymoe@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:39:11 by ymoe              #+#    #+#             */
/*   Updated: 2026/06/07 15:39:11 by ymoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_in_row(char **grid, int row, int col, int digit)
{
	int	i;

	i = 1;
	while (i < col)
	{
		if (grid[row][i] == digit + '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_in_column(char **grid, int row, int col, int digit)
{
	int	i;

	i = 1;
	while (i < row)
	{
		if (grid[i][col] == digit + '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
