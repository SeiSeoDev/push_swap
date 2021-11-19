/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:12:20 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 17:35:38 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_pile *lst)
{
	int	i;

	if (lst->max_b == 0)
		return (-1);
	i = lst->max_a - 1;
	while (i >= 0)
	{
		lst->a[i + 1] = lst->a[i];
		i--;
	}
	i = 0;
	lst->a[0] = lst->b[0];
	while (i < lst->max_b)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->max_a++;
	lst->max_b--;
	ft_putstr("pa\n");
	return (pa);
}
