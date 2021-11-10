#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef enum s_act
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_act;

typedef struct s_pile
{
	int				valid;
	int				*a;
	int				*b;
	int				index;
	int				max_a;
	int				max_b;
}	t_pile;

/*
** actions.c
*/

int					swap_a(t_pile *lst);
int					swap_b(t_pile *lst);
int					swap_s(t_pile *lst);
int					push_a(t_pile *lst);
int					push_b(t_pile *lst);

int					revers_a(t_pile *lst);
int					revers_b(t_pile *lst);
int					revers_r(t_pile *lst);

int					rrevers_a(t_pile *lst);
int					rrevers_b(t_pile *lst);
int					rrevers_r(t_pile *lst);

/*
** radix.c
*/

void radix_sort(t_pile *pile);

#endif