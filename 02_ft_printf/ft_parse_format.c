#include "libft.h"

char	parse_format(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			return ((char)*str);
		}
		str++;
	}
	return ('s');
}
