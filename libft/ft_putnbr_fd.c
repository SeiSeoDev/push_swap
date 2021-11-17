#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb >= 0)
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		else
		{
			ft_putchar_fd(nb + 48, fd);
		}
	}
	else if (nb > -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = (nb * -1);
		ft_putnbr_fd(nb, fd);
	}
	else
		ft_putstr_fd("-2147483648", fd);
}
