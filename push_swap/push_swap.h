/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 07:49:56 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/21 16:46:18 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <unistd.h>

# define TOPA		all->a->pile[all->a->len - 1]
# define TOPB		all->b->pile[all->b->len - 1]
# define LENA		all->a->len
# define LENB		all->b->len
# define PIVI		all->pivot
# define PIVV		all->a->pile[all->pivot]

typedef struct		s_pile
{
	int				*pile;
	int				len;
}					t_pile;

typedef struct		s_all
{
	t_pile			*a;
	t_pile			*b;
	int				op;
	int				opv;
	int				ops;
	int				ope;
	int				opo;
	int				opc;
	int				pivot;
}					t_all;

t_pile				*check_stock(char **tab);
void				*free_return(void *fr, void *re);
int					error_return(void);
void				show_pile(t_all *all);

int					sort(t_all *all);
int					sa_sort(t_all *all);
int					sb_sort(t_all *all);
int					ss_sort(t_all *all);
int					pa_sort(t_all *all);
int					pb_sort(t_all *all);
int					ra_sort(t_all *all);
int					rb_sort(t_all *all);
int					rr_sort(t_all *all);
int					rra_sort(t_all *all);
int					rrb_sort(t_all *all);
int					rrr_sort(t_all *all);

int					little_sort(t_all *all);
void				insert_sort(t_all *all);
int					quick_sort(t_all *all, int start, int end);
int					where_a_in_b(t_all *all);
int					check_part(t_all *all, int start, int end);
int					check_allrev(t_pile *a, int start, int end);
int					get_max(t_pile *b);
#endif
