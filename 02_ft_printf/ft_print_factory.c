#include "libft.h"

static void	print_str(va_list toprint)
{
	char	*res;

	res = va_arg(toprint, char *);
	if (!res)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(res, 1));
}

static void	print_ptr(va_list toprint)
{
	int	num;
	
	// The prefix for hexadecimal is "0x"
	ft_putstr_fd("0x", 1);
	num = va_arg(toprint, int);
	if (!num)
		return (ft_putnbr_fd(0, 1));
	return (ft_putnbr_base(num, "0123456789abcdef"));
}

// c s p d i u x X %
void	print_factory(va_list toprint, char flag)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(toprint, int), 1));
	if (flag == 's')
		return (print_str(toprint));
	if (flag == 'p')
		return (print_ptr(toprint));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr_fd(va_arg(toprint, int), 1));
	if (flag == 'u')
		return (ft_putnbr_fd((unsigned int)va_arg(toprint, unsigned int), 1));
	if (flag == 'x')
		return (ft_putnbr_base(va_arg(toprint, int), "0123456789abcdef"));
	if (flag == 'X')
		return (ft_putnbr_base(va_arg(toprint, int), "0123456789ABCDEF"));
	if (flag == '%')
		return (ft_putchar_fd('%', 1));
}
