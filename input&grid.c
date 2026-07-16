/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input&grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachow <yachow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:28:18 by yachow            #+#    #+#             */
/*   Updated: 2026/06/07 20:28:57 by yachow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

char	**alloc_grid(int rows, int cols)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = malloc(sizeof(char) * cols);
		if (!grid[i])
		{
			while (i > 0)
				free(grid[--i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

char	**build_grid(void)
{
	char	**board;
	int		i;
	int		j;

	board = alloc_grid(6, 6);
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = '0';
			j ++;
		}
		i++;
	}
	return (board);
}

int	valid_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] < '1' || argv[1][i] > '4')
				return (0);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i++;
	}
	if (i == 31)
		return (1);
	return (0);
}

char	**parse_input(char *str)
{
	char	**clues;
	int		group;
	int		pos;
	int		i;

	clues = alloc_grid(4, 4);
	if (!clues)
		return (0);
	group = 0;
	i = 0;
	while (group < 4)
	{
		pos = 0;
		while (pos < 4)
		{
			clues[group][pos] = str[i];
			i += 2;
			pos++;
		}
		group++;
	}
	return (clues);
}

// //test with ./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// }

// void	print_grid(char **grid, int rows, int cols)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			ft_putchar(grid[i][j]);
// 			if (j != cols - 1)
// 				ft_putchar(' ');
// 			j++;
// 		}
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

// void	free_grid(char **grid, int rows)
// {
// 	int	i;

// 	i = 0;
// 	while (i < rows)
// 	{
// 		free(grid[i]);
// 		i++;
// 	}
// 	free(grid);
// }

// int	main(int argc, char **argv)
// {
// 	char	**grid;
// 	char	**clues;

// 	if (argc != 2)
// 	{
// 		ft_putstr("Usage: ./a.out \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n");
// 		return (0);
// 	}

// 	ft_putstr("Testing valid_input:\n");
// 	if (valid_input(argv))
// 		ft_putstr("Input is valid\n");
// 	else
// 	{
// 		ft_putstr("Input is invalid\n");
// 		return (0);
// 	}

// 	ft_putstr("\nTesting build_grid:\n");
// 	grid = build_grid();
// 	if (grid == NULL)
// 	{
// 		ft_putstr("build_grid failed\n");
// 		return (0);
// 	}
// 	print_grid(grid, 6, 6);

// 	ft_putstr("\nTesting parse_input:\n");
// 	clues = parse_input(argv[1]);
// 	if (clues == NULL)
// 	{
// 		ft_putstr("parse_input failed\n");
// 		free_grid(grid, 6);
// 		return (0);
// 	}
// 	print_grid(clues, 4, 4);

// 	free_grid(grid, 6);
// 	free_grid(clues, 4);

// 	return (0);
// }
