/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:27 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 17:35:48 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_pile *pile)
{
	int	i;
	int	last;

	last = pile->a[0];
	i = 1;
	if (pile->max_a <= 1)
		return (1);
	while (pile->max_a > i && pile->a[i] > last)
	{
		last = pile->a[i];
		i++;
	}
	if (i == pile->max_a)
		return (1);
	return (0);
}

int	ftatoi(const char *str, t_pile *pile)
{
	int						i;
	int						neg;
	unsigned long long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	if (nb > 2147483648 || (nb > 2147483647 && neg == 1))
		custom_exit(pile, EXIT_FAILURE);
	return ((int)nb * neg);
}

int	is_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	check_double(t_pile *pile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pile->max_a)
	{
		j = 0;
		while (j < pile->max_a)
		{
			if (pile->a[i] == pile->a[j] && j != i)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
