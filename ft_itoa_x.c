#include "ft_printf.h"

int	func_len_x(unsigned int i)
{
	int	p;

	p = 0;
	while (i)
		i /= 16, p++;
	return (p);
}

char	*ft_putnbr_char_x(unsigned int n, char *str, int masslen)
{
	str[masslen] = '\0';
	while (n)
	{
		if (n % 16 <= 9)
			str[--masslen] = n % 16 + '0';
		if (n % 16 > 9)
			str[--masslen] = n % 16 + 'a' - 10;
		n /= 16;
	}
	return (str);
}

char	*ft_putnbr_char_X(unsigned int n, char *str, int masslen)
{
	str[masslen] = '\0';
	while (n)
	{
		if (n % 16 <= 9)
			str[--masslen] = n % 16 + '0';
		if (n % 16 > 9)
			str[--masslen] = n % 16 + 'A' - 10;
		n /= 16;
	}
	return (str);
}

char	*ft_itoa_x(unsigned int n, t_printf *st)
{
	char	*str;
	int		masslen;

	if (n == 0)
		return (ft_strdup("0"));
	masslen = func_len_x(n);
	str = (char *)malloc(sizeof(char) * (masslen + 1));
	if (!str)
		return (NULL);
	else if (st->id == 'X')
		return (ft_putnbr_char_X(n, str, masslen));
	return (ft_putnbr_char_x(n, str, masslen));
}
