#include "push_swap.h"

int	get_min(int *a, int size)
{
	int	i;
	int	ret;

	i = 1;
	ret = a[0];
	while (i < size)
	{
		if (ret > a[i])
			ret = a[i];
		i++;
	}
	return (ret);
}

int	where_to_go(t_pile *pile, int nb)
{
	int	i;

	i = 0;
	while (pile->a[i] != nb)
		i++;
	if (i > (pile->max_a / 2))
		return (0);
	else
		return (1);
}

void	custom_sort(t_pile *pile, int min)
{
	if (pile->a[0] == min)
	{
		if (pile->a[1] == min + 2)
		{
			swap_a(pile);
			revers_a(pile);
		}
	}
	else if (pile->a[1] == min)
	{
		if (pile->a[0] == min + 2)
			revers_a(pile);
		else
			swap_a(pile);
	}
	else
	{
		if (pile->a[0] == min + 2)
		{
			swap_a(pile);
			rrevers_a(pile);
		}
		else
			rrevers_a(pile);
	}
}

void	bubble_sort(t_pile *pile)
{
	while (!is_sort(pile) && pile->max_a > 3)
	{
		while (pile->max_a > 0 && pile->a[0] != pile->max_b)
		{
			if (where_to_go(pile, pile->max_b))
				revers_a(pile);
			else
				rrevers_a(pile);
		}
		if (!is_sort(pile))
			push_b(pile);
	}
	if (pile->max_a <= 3 && !is_sort(pile))
		custom_sort(pile, get_min(pile->a, pile->max_a));
	while (pile->max_b > 0)
		push_a(pile);
}
