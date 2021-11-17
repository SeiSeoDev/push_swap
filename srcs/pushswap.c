/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:25:51 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 17:32:11 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	custom_exit(t_pile *pile, int ret)
{
	if (pile)
	{
		if (pile->a)
			free(pile->a);
		if (pile->b)
			free(pile->b);
		free(pile);
	}
	if (ret == EXIT_FAILURE)
		ft_putstr("Error\n");
	exit(ret);
}

void	clean_pile(t_pile *pile)
{
	int	i;

	i = 0;
	while (i < pile->max_a)
	{
		pile->a[i] = pile->b[i];
		pile->b[i] = 0;
		i++;
	}
}

int	*convert_as_min(int size, t_pile *pile)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	while (i < size)
	{
		j = 0;
		save = 0;
		while (j < size)
		{
			if (pile->a[i] > pile->a[j])
				save++;
			j++;
		}
		pile->b[i] = save;
		i++;
	}
	return (pile->b);
}

void	fill_pile_a(t_pile *pile, int size, char **av)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_nbr(av[i + 1]))
		{
			custom_exit(pile, EXIT_FAILURE);
		}
		pile->a[i] = ftatoi(av[i + 1], pile);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_pile	*pile;

	pile = malloc(sizeof(t_pile));
	pile->a = malloc((ac - 1) * sizeof(int));
	pile->b = malloc((ac - 1) * sizeof(int));
	if (!pile || !pile->a || !pile->b)
		custom_exit(pile, EXIT_FAILURE);
	fill_pile_a(pile, ac - 1, av);
	pile->max_a = ac - 1;
	if (!check_double(pile))
		custom_exit(pile, EXIT_FAILURE);
	pile->b = convert_as_min(ac - 1, pile);
	pile->max_b = 0;
	clean_pile(pile);
	if (is_sort(pile))
		return (0);
	if (pile->max_a <= 3)
		custom_sort(pile, 0);
	else if (pile->max_a < 64)
		 bubble_sort(pile);
	else
		radix_sort(pile);
	custom_exit(pile, EXIT_SUCCESS);
}
