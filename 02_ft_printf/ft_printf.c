#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	flag;

	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			flag = parse_format(str);
			print_factory(args, flag);
			str += 2;
		}
		else
		{
			ft_putchar_fd((char)*str, 1);
			str++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%x\n", "salut");
	printf("%%\n");
	ft_printf("%%\n");
	return (0);
}
