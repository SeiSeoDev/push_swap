#include "push_swap.h"

void test(int ac, int *tab)
{
    int i;
    printf("________________________________\n");
    i = 0;
    while (i < ac)
    {
        printf("%d - ", tab[i]);
        i++;
    }
    printf("\n");
}

int where_to_go(t_pile *pile, int nb)
{
    int i;

    i = 0;
    while(pile->a[i] != nb)
        i++;
    if (i > (pile->max_a / 2))
        return (0);
    else
        return (1);
}
void	custom_sort(t_pile *pile)
{
	if (pile->a[0] == 0)
	{
		if (pile->a[1] == 2)
		{
			swap_a(pile);
			revers_a(pile);
		}
	}
	else if (pile->a[1] == 0)
	{
		if (pile->a[0] == 2)
			revers_a(pile);
		else
			swap_a(pile);
	}
	else
	{
		if (pile->a[0] == 2)
		{
			swap_a(pile);
			rrevers_a(pile);
		}
		else
			rrevers_a(pile);
	}
}

void bubble_sort(t_pile *pile)
{
    while (!is_sort(pile))
    {
        while(pile->max_a > 0 && pile->a[0] != pile->max_b)
        {
            if (where_to_go(pile, pile->max_b))
                revers_a(pile);
            else
                rrevers_a(pile);
        }
        push_b(pile);
        if (pile->max_a <= 3 && !is_sort(pile))
            custom_sort(pile);
    }
    while (pile->max_b > 0)
        push_a(pile);
}