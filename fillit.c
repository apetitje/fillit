/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:56:40 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/18 11:00:08 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		display(int size_m, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size_m)
	{
		j = -1;
		while (++j < size_m)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}

static void		ft_list_del(t_lst **lst)
{
	t_lst	*to_del;
	t_lst	*next;

	if (*lst)
	{
		to_del = *lst;
		while (to_del)
		{
			next = to_del->next;
			free(to_del);
			to_del = next;
		}
	}
	*lst = NULL;
}

static void		ft_free_map(char ***map, int map_size)
{
	int		i;

	i = -1;
	if (*map)
	{
		while (++i < map_size)
			free((*map)[i]);
		free(*map);
	}
}

int				bigger_map(char ***map, int map_size)
{
	int		i;

	i = -1;
	ft_free_map(map, map_size);
	map_size += 1;
	if (!(*map = (char **)malloc(sizeof(char*) * map_size)))
		exit(-2);
	while (++i < map_size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * map_size)))
			exit(-2);
		ft_memset((*map)[i], (int)'.', map_size);
	}
	return (map_size);
}

int				main(int argc, char **argv)
{
	int		map_size;
	char	**map;
	t_lst	*lst;

	lst = NULL;
	map_size = 0;
	if (argc != 2)
	{
		ft_putstr("usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" file\n");
	}
	else if (ft_read_input(argc, argv, &map_size, &lst) != 0)
		write(1, "error\n", 6);
	else
	{
		bigger_map(&map, map_size - 1);
		map_size = solver(lst, map_size, &map);
		display(map_size, map);
		ft_free_map(&map, map_size);
		ft_list_del(&lst);
	}
	return (0);
}
