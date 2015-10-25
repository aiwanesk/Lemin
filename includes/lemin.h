/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 06:21:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 11:51:31 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef enum		e_status
{
	BASIC,
	START,
	END,
}					t_status;

typedef struct		s_salle
{
	char			*name;
	int				x;
	int				y;
	int				indice;
	t_status		status;
	int				used;
	int				dist;
	t_list			*link;
	int				way_value;
	int				clean;
	int				simple;
	int				useless;
}					t_salle;

void				resolve(t_list *list, int ant);
int					get_ant(void);
int					set_ant(int modif);
void				print_list(t_list *list);
void				find_all_path(t_list *list, const int value);
void				omg(t_list *list, int value, int ant);
void				print(t_list *list, int path, int ant);
void				give_value(t_salle *salle);
void				reinit_dist(t_list *list);
void				compute_way(int ant, int *every_path, int len,
					t_list *list);
void				particular(int *possible, int i, int ant, t_list *list);
void				ft_error(void);
int					find_short_link_norme(t_list *list, int ret);
t_list				*ret_end(t_list *list);
int					lin_parse_comm(char *str, t_status *status);
char				*lin_parse_first(t_list **list);
void				move_ant(int *ant_per_path, t_list *list, int len);
int					move(t_list *list);
void				print_move(t_list *list);
void				iter_path(t_list *list, int path_length);
void				init_useless(t_list *list);
void				move_end(t_list *list);
void				init_clean(t_list *list);
void				add_ant(int name, t_list *list, int path);
void				single_path(t_list *list, int ant);
void				clean_end(t_list *list);
void				single_path(t_list *list, int ant);
void				iter_path(t_list *list, int path_length);
int					choice(t_list *list);
t_list				*simple_choice(t_list *link);
void				fast_end(t_list *list, int ant);
void				base_check(t_list *list);
void				is_possible(t_list *list);
void				spag(t_list *list);
void				move_simple(t_list *list);
void				move_basic(t_list *link);
void				iter_simple(t_list *list, int path);
void				single_path(t_list *list, int ant);
void				replace(char **str, t_list *list, int ant);
void				change_status(t_list *list, int i, int ant);
void				run(t_list *list, int ant);
char				*stradd(char *tocopy, char *str);
char				*change_name(char *str, t_list *list);
void				clean_useless(t_list *list);
void				add_simple(int tot, t_list *list);
void				clean_last(t_list *list);
void				change_status(t_list *list, int i, int ant);

#endif
