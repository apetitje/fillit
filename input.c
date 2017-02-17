/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:39:38 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/18 10:52:30 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_create_tetri(int tab_coord[4], char tetri_char, t_lst **lst)
{
	t_lst	*new_ele;
	int		j;
	t_lst	*tmp;

	j = -1;
	if (!(new_ele = (t_lst *)malloc(sizeof(t_lst))))
		exit(-2);
	ft_memset((new_ele->tetri)[0], '.', 16);
	while (++j < 4)
		(new_ele->tetri)[0][tab_coord[j]] = tetri_char;
	new_ele->next = NULL;
	if (*lst == NULL)
	{
		*lst = new_ele;
		lst = &new_ele;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_ele;
	}
	return (0);
}

static int		ft_init_var(int *i_tab, int *first, int *is_linked)
{
	int		end;

	*i_tab = 0;
	*first = -1;
	end = 20;
	*is_linked = 0;
	return (end);
}

static int		ft_convert_tetri(char *str, int i, t_lst **lst, int *nb_tetri)
{
	int		tab_coord[4];
	int		i_tab;
	int		end;
	int		first;
	int		is_linked;

	end = i + ft_init_var(&i_tab, &first, &is_linked);
	while (i < end)
	{
		while (i < end && (str[i] == '.' || str[i] == '\n'))
			i++;
		if (str[i] == '#')
		{
			is_linked = is_linked + ft_first_excepts(i, &first, end, str);
			if (i_tab == 4)
				return (-1);
			tab_coord[i_tab++] = i - first - (i - first) / 4;
			i++;
		}
		else if (str[i] != '\0' && str[i] != '\n' && str[i] != '.')
			return (-1);
	}
	return ((i_tab != 4 || is_linked / 2 < 3) ? -1 : ft_create_tetri(tab_coord,
				(char)((*nb_tetri)++) + 65, lst));
}

static int		ft_process_str(char *str, t_lst **lst)
{
	int		end_line_nb;
	int		i_begin;
	int		nb_tetri;
	int		i;

	nb_tetri = 0;
	i = 0;
	while (str[i])
	{
		i_begin = i--;
		end_line_nb = 0;
		while (str[++i] && end_line_nb < 4)
			if (str[i] == '\n')
				end_line_nb++;
		if (--i + 1 - i_begin != 20)
			return (-1);
		while (str[++i] == '\n')
			end_line_nb++;
		if (ft_nb_line(end_line_nb, i, str) == -1
				|| ft_convert_tetri(str, i_begin, lst, &nb_tetri) == -1)
			return (-1);
	}
	return (nb_tetri);
}

int				ft_read_input(int argc, char **argv, int *map_size, t_lst **lst)
{
	char	buffer[BUFFSIZE + 1];
	int		fd;
	char	*str;
	int		ret;
	int		nb_tetri;

	fd = 0;
	str = NULL;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
		exit(-2);
	while ((ret = read(fd, buffer, BUFFSIZE)))
	{
		buffer[ret] = '\0';
		if (str)
			return (-1);
		str = ft_strdup(buffer);
	}
	close(fd);
	if (!str)
		return (-1);
	if ((nb_tetri = ft_process_str(str, lst)) == -1)
		return (-1);
	*map_size = ft_sqrt_approx(nb_tetri * 4);
	return (0);
}
