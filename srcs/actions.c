/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:12:00 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 17:12:01 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->a[i] = tmp;
	ft_putstr("ra\n");
	return (ra);
}

int	revers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->b[0];
	while (i < lst->max_b - 1)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->b[i] = tmp;
	ft_putstr("rb\n");
	return (rb);
}

int	revers_r(t_pile *lst)
{
	revers_a(lst);
	revers_b(lst);
	ft_putstr("rr\n");
	return (rr);
}

int	rrevers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a - 1;
	tmp = lst->a[i];
	while (i > 0)
	{
		lst->a[i] = lst->a[i - 1];
		i--;
	}
	lst->a[i] = tmp;
	ft_putstr("rra\n");
	return (rra);
}

int	rrevers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_b - 1;
	tmp = lst->b[i];
	while (i > 0)
	{
		lst->b[i] = lst->b[i - 1];
		i--;
	}
	lst->b[i] = tmp;
	ft_putstr("rrb\n");
	return (rrb);
}
