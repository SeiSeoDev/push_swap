#include "push_swap.h"

int	revers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->a[i] = tmp;
    ft_putstr("ra\n");
	return (ra);
}

int	revers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->b[0];
	while (i < lst->max_b - 1)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->b[i] = tmp;
    ft_putstr("rb\n");
	return (rb);
}

int	revers_r(t_pile *lst)
{
	revers_a(lst);
	revers_b(lst);
    ft_putstr("rr\n");
	return (rr);
}
int	rrevers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a - 1;
	tmp = lst->a[i];
	while (i > 0)
	{
		lst->a[i] = lst->a[i - 1];
		i--;
	}
	lst->a[i] = tmp;
    ft_putstr("rra\n");
	return (rra);
}

int	rrevers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_b - 1;
	tmp = lst->b[i];
	while (i > 0)
	{
		lst->b[i] = lst->b[i - 1];
		i--;
	}
	lst->b[i] = tmp;
    ft_putstr("rrb\n");
	return (rrb);
}

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
	while (i < lst->max_a)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->max_a--;
	lst->max_b++;
    ft_putstr("pb\n");
	return (pb);
}

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