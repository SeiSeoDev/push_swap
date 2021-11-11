#include "push_swap.h"

int get_max_bits(t_pile *pile)
{
    int ret;
    int max;

    max = pile->max_a-1;
    ret = 0;
    while(max)
    {
        max = max >>1;
        ret++;
    }
    return (ret);
}

void radix_sort(t_pile *pile)
{
    int max_bit;
    int bit;
    int i;

    bit = 0;
    max_bit = get_max_bits(pile);
    while (bit < max_bit)
    {
        i = 0;
        if (is_sort(pile))
            return;
        while(i < pile->max_a)
        {
            if ((pile->a[0] >> bit) % 2 == 0)
                push_b(pile);
            else
            {
                revers_a(pile);
                i++;
            }
        }
        while (pile->max_b > 0)
		    push_a(pile);
        bit++;
    }
}
