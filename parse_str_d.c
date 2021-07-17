#include "ft_printf.h"

void	for_str_f_d(t_printf *st, char s, char *t)
{
	int	l;
	int	w;
	int	z;

	l = 0;
	w = 0;
	z = 0;
	if (st->pr < 0 && st->dot && st->zero && st->vv > 0)
		st->pr = st->vv;
	if (*t == '0' && st->pr == 0 && st->dot)
		*t = '\0';
	l = (int)ft_strlen(t);
	if (st->pr > l)
		z = st->pr - l;
	w = st->vv - l - z;
	for_str_s_d(st, s, w, z);
	for_str_t_d(st, l, w, t);
}

void	for_str_s_d(t_printf *st, int s, int w, int z)
{
	if (!(st->zero && !st->dot) && !st->minus)
		while (w-- > 0)
			st->length += write(1, " ", 1);
	if (s)
		st->length += write(1, "-", 1);
	if (st->zero && !st->dot)
		while (w-- > 0)
			st->length += write(1, "0", 1);
	while (z-- > 0)
		st->length += write(1, "0", 1);
}

void	for_str_t_d(t_printf *st, int l, int w, char *t)
{
	st->length += write(1, t, l);
	if (!(st->zero && !st->dot) && st->minus)
		while (w-- > 0)
			st->length += write(1, " ", 1);
}

void	parse_str_d(va_list args, t_printf *st)
{
	char	*tmp;
	int		num;
	char	sign;

	sign = 0;
	num = (int)va_arg(args, int);
	if (num < 0)
	{
		sign = '-';
		st->vv -= 1;
	}
	tmp = ft_itoa(num);
	for_str_f_d(st, sign, tmp);
	free(tmp);
}
