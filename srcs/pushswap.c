
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

/*
int get_ac(char *str)
{
    int i;
    int nb;

    nb = 0;
    i = 0;
    while(i < (int)ft_strlen(str) - 1)
    {
        if (((i > 0 && (str[i - 1] == ' ')) || (str[i + 1] && (str[i + 1] == ' '))) && (str[i] >= '0' && str[i] <= '9'))
        {
            nb++;
            printf("%c\n", str[i]);
        }
        i++;
    }
    printf("%d\n", nb);
    return (nb);
}*/
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
void custom_exit(t_pile *pile, int ret)
{
    if (pile)
    {
        if (pile->a)
            free(pile->a);
        if (pile->b)
            free(pile->b);
        free(pile);
    }
    if ( ret == EXIT_FAILURE)
        ft_putstr("Error\n");
	exit(ret);
}

int check_double(t_pile *pile)
{
    int i;
    int j;

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

int is_sort(t_pile *pile)
{
    int i;
    int last;

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

void clean_pile(t_pile *pile)
{
    int i = 0;
    while (i < pile->max_a)
    {
        pile->a[i] = pile->b[i];
        pile->b[i] = 0;
        i++;
    }
}
int	ftatoi(const char *str, t_pile *pile)
{
	int				i;
	int				neg;
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

int *convert_as_min(int size, t_pile *pile)
{
    int i;
    int j;
    int save;
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
int is_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '+')
            return (0);
        i++;
    }
    return (1);
}

void fill_pile_a(t_pile *pile, int size, char **av)
{
    int i;
    i = 0;
    while(i < size)
    {
        if (!is_nbr(av[i+1]))
        {
            custom_exit(pile, EXIT_FAILURE);
        }
        pile->a[i] = ftatoi(av[i+1], pile);
        i++;
    }
}

int main(int ac, char **av)
{
    t_pile *pile;

    /// début des mallocs
    pile = malloc(sizeof(t_pile));
    pile->a = malloc((ac - 1) * sizeof(int));
    pile->b = malloc((ac - 1) * sizeof(int));
    /// fin des mallocs
    fill_pile_a(pile, ac-1, av);
    pile->max_a = ac-1;
    if (!check_double(pile))
        custom_exit(pile, EXIT_FAILURE);
    pile->b = convert_as_min(ac-1, pile);
    pile->max_b = 0;
   // test(ac - 1, pile->a);
    //test(ac - 1, pile->b);
    /*test(ac - 1, pile->a);
    test(ac - 1, pile->b);
    */
    clean_pile(pile);
    //test(ac - 1, pile->b);
    //test(ac - 1, pile->a);
    if (is_sort(pile))
        return (0);
    if (pile->max_a <= 3)
        custom_sort(pile, 0);
    else if (pile->max_a < 64)
         bubble_sort(pile);
    else
        radix_sort(pile);
   // test(pile->max_a, pile->a);
    //test(pile->max_b, pile->b);
//  test(ac - 1, pile->a);
    /*
    convert_as_bin()
    size ?
        bruteforce()
        radix_sort()
    */
}