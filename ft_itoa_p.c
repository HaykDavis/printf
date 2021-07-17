#include "ft_printf.h"

int	func_len_p(unsigned long i)
{
	int	p;

	p = 1;
	while (i > 15)
		i /= 16, p++;
	return (p);
}

char	*ft_putnbr_char_p(unsigned long n, char *str, int masslen)
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

char	*ft_itoa_p(unsigned long n)
{
	char	*str;
	int		masslen;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	masslen = func_len_p(n);
	str = (char *)malloc(sizeof(char) * masslen + 1);
	if (!str)
		return (NULL);
	else
		return (ft_putnbr_char_p(n, str, masslen));
}
