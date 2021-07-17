#include "ft_printf.h"

int	func_len_u(unsigned int i)
{
	int	p;

	p = 1;
	while (i > 9)
		i /= 10, p++;
	return (p);
}

char	*ft_putnbr_char_u(unsigned int n, char *str, int masslen)
{
	str[masslen] = '\0';
	str[--masslen] = n % 10 + '0';
	while (n > 9)
	{
		n /= 10;
		str[--masslen] = n % 10 + '0';
	}
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		masslen;

	if (!n)
		return (ft_strdup("0"));
	if (n < 0)
		n = -n;
	if (n < 0)
		masslen = func_len_u(n) + 1;
	else
		masslen = func_len_u(n);
	str = (char *)malloc(sizeof(char) * (masslen + 1));
	if (!str)
		return (NULL);
	return (ft_putnbr_char_u(n, str, masslen));
}
