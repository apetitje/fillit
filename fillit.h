/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:38:02 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/17 11:45:25 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_lst
{
	char			tetri[4][4];
	struct s_lst	*next;
}					t_lst;

int					ft_sqrt_approx(int nb);
int					ft_first_excepts(int i, int *first, int end, char *str);
int					ft_strlen(const char *s);
int					ft_is_linked(char *str, int i, int first, int end);
int					ft_nb_line(int end_line_nb, int i, char *str);
int					ft_read_input(int argc, char **argv,
						int *map_size, t_lst **lst);
int					solver(t_lst *lst, int size_m, char ***map);
int					bigger_map(char ***map, int map_size);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);

# define BUFFSIZE	545

#endif
