/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachow <yachow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:11:45 by yachow            #+#    #+#             */
/*   Updated: 2026/06/07 17:11:45 by yachow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	print_error(void);
void	print_sol(char **puzzle_board);
void	fill_borders(char **puzzle_board, char **clues);
char	**alloc_grid(int rows, int columns);
char	**build_grid(void);
char	**parse_input(char *str);
int		valid_input(char **argv);
void	recursive_loop(char **grid, int row, int col);
void	loop(char **clues);
int		is_correct_right_view(char **grid, int row);
int		is_correct_left_view(char **grid, int row);
int		is_correct_bottom_view(char **grid, int col);
int		is_correct_top_view(char **grid, int col);
int		is_valid_view(char **grid, int row, int col);
int		is_in_row(char **grid, int row, int col, int digit);
int		is_in_column(char **grid, int row, int col, int digit);

#endif