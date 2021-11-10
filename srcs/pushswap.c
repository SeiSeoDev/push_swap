#include <stdlib.h>
#include <stdio.h>
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

int *fill_pile_a(int *a, int size, char **av)
{
    int i;

    i = 0;
    while(i < size)
    {
        a[i] = atoi(av[i+1]);
        i++;
    }
    return (a);
}

int main(int ac, char **av)
{
    t_pile *pile;

    /// début des mallocs
    pile = malloc(sizeof(t_pile));
    pile->a = malloc((ac - 1) * sizeof(int));
    pile->b = malloc((ac - 1) * sizeof(int));
    /// fin des mallocs

    pile->a = fill_pile_a(pile->a, ac-1, av);
    pile->b = convert_as_min(ac-1, pile);
    pile->max_a = ac-1;
    pile->max_b = 0;
   // test(ac - 1, pile->a);
    //test(ac - 1, pile->b);
    /*test(ac - 1, pile->a);
    test(ac - 1, pile->b);
    */
    clean_pile(pile);
    //test(ac - 1, pile->b);
    //test(ac - 1, pile->a);

    radix_sort(pile);
 //  test(ac - 1, pile->a);
    /*
    convert_as_bin()
    size ?
        bruteforce()
        radix_sort()
    */
}