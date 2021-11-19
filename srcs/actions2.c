/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:09:29 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/19 17:47:01 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrevers_r(t_pile *lst)
{
	rrevers_a(lst);
	rrevers_b(lst);
	ft_putstr("rrr\n");
	return (rrr);
}

int	swap_a(t_pile *lst)
{
	int	tmp;

	tmp = lst->a[0];
	lst->a[0] = lst->a[1];
	lst->a[1] = tmp;
	ft_putstr("sa\n");
	return (sa);
}

int	swap_b(t_pile *lst)
{
	int	tmp;

	tmp = lst->b[0];
	lst->b[0] = lst->b[1];
	lst->b[1] = tmp;
	ft_putstr("sb\n");
	return (sb);
}

int	swap_s(t_pile *lst)
{
	swap_a(lst);
	swap_b(lst);
	ft_putstr("ss\n");
	return (ss);
}

int	push_b(t_pile *lst)
{
	int	i;

	if (lst->max_a == 0)
		return (-1);
	i = lst->max_b - 1;
	while (i >= 0)
	{
		lst->b[i + 1] = lst->b[i];
		i--;
	}
	i = 0;
	lst->b[0] = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->max_a--;
	lst->max_b++;
	ft_putstr("pb\n");
	return (pb);
}
