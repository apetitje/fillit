/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:37:34 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/17 11:15:54 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_linked(char *str, int i, int first, int end)
{
	int		is_linked;

	is_linked = 0;
	if (i + 1 < end && str[i + 1] == '#')
		is_linked++;
	if (i - 1 >= first && str[i - 1] == '#')
		is_linked++;
	if (i + 5 < end && str[i + 5] == '#')
		is_linked++;
	if (i - 5 >= first && str[i - 5] == '#')
		is_linked++;
	return (is_linked);
}

int		ft_first_excepts(int i, int *first, int end, char *str)
{
	int		is_linked;

	if (*first == -1)
	{
		*first = i;
		if (*first != 0 && *first + 3 < end && *first + 4 < end
				&& *first + 5 < end && str[*first + 3] == '#'
				&& str[*first + 4] == '#' && str[*first + 5] == '#')
			*first -= 2;
		else if (*first != 0 && ((*first + 9 < end && str[*first + 9] == '#')
				|| (*first + 4 < end && str[*first + 4] == '#')))
			(*first)--;
	}
	is_linked = ft_is_linked(str, i, *first, end);
	return (is_linked);
}

int		ft_nb_line(int end_line_nb, int i, char *str)
{
	if (end_line_nb > 5 || (end_line_nb == 4 && str[i] != '\0')
			|| (end_line_nb > 4 && str[i] == '\0'))
		return (-1);
	return (0);
}

int		ft_sqrt_approx(int nb)
{
	int sqrt;
	int mult;

	sqrt = 0;
	mult = 1;
	while (nb > mult * mult)
		mult++;
	return (mult);
}
