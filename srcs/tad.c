static void	binary_sort(t_pile *lst, int bit)
{
	int	len;

	len = 0;
	while (len < lst->max_a)
	{
		if (((lst->a[0] >> bit) % 2) == 0)
			put_res(lst, &push_b);
		else
		{
			put_res(lst, &revers_a);
			len++;
		}
	}
	len = 0;
	while (len < lst->max_b)
		put_res(lst, &push_a);
}

void	radix_sort(t_pile *lst)
{
	int	bit;
	int	max_bit;

	bit = 0;
	max_bit = get_max_bits(lst);
	while (bit < max_bit)
	{
		binary_sort(lst, bit);
		if (check_all(lst))
			lst->valid = 1;
		bit++;
	}
}