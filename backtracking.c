/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:03:05 by nmuller           #+#    #+#             */
/*   Updated: 2016/11/17 11:07:10 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetri(char tetri[4][4], int line, int col, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri[i][j] != '.')
				map[line + i][col + j] = tetri[i][j];
		}
	}
}

void	remove_tetri(char tetri[4][4], int size_m, char **map)
{
	int		i;
	int		j;
	char	id;

	if (tetri[0][0] != '.')
		id = tetri[0][0];
	else if (tetri[0][1] != '.')
		id = tetri[0][1];
	else
		id = tetri[0][2];
	i = -1;
	while (++i < size_m)
	{
		j = -1;
		while (++j < size_m)
		{
			if (map[i][j] == id)
				map[i][j] = '.';
		}
	}
}

int		case_ok(char tetri[4][4], int cursor, char **map, int size_m)
{
	int		i;
	int		j;
	int		line;
	int		col;
	int		nb_placed;

	nb_placed = 0;
	line = cursor / size_m;
	col = cursor % size_m;
	i = -1;
	while (++i < 4 && line + i < size_m)
	{
		j = -1;
		while (++j < 4 && col + j < size_m)
		{
			if (map[line + i][col + j] != '.' && tetri[i][j] != '.')
				return (0);
			else if (map[line + i][col + j] == '.' && tetri[i][j] != '.')
				++nb_placed;
		}
	}
	return (nb_placed == 4);
}

int		core(t_lst *lst, int size_m, char **map)
{
	int		cursor;

	cursor = -1;
	if (!lst)
		return (1);
	while (++cursor < size_m * size_m)
	{
		if (case_ok(lst->tetri, cursor, map, size_m))
		{
			place_tetri(lst->tetri, cursor / size_m, cursor % size_m, map);
			if (core(lst->next, size_m, map))
				return (1);
			else
				remove_tetri(lst->tetri, size_m, map);
		}
	}
	return (0);
}

int		solver(t_lst *lst, int size_m, char ***map)
{
	while (!core(lst, size_m, *map))
		size_m = bigger_map(map, size_m);
	return (size_m);
}
