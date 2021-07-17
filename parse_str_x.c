#include "ft_printf.h"

void	for_str_f_x(t_printf *st, char *t)
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
	for_str_s_x(st, w, z);
	for_str_t_x(st, l, w, t);
}

void	for_str_s_x(t_printf *st, int w, int z)
{
	if (!(st->zero && !st->dot) && !st->minus)
		while (w-- > 0)
			st->length += write(1, " ", 1);
	if (st->zero && !st->dot)
		while (w-- > 0)
			st->length += write(1, "0", 1);
	while (z-- > 0)
		st->length += write(1, "0", 1);
}

void	for_str_t_x(t_printf *st, int l, int w, char *t)
{
	st->length += write(1, t, l);
	if (!(st->zero && !st->dot) && st->minus)
		while (w-- > 0)
			st->length += write(1, " ", 1);
}

void	parse_str_x(va_list args, t_printf *st)
{
	char				*tmp;
	unsigned long		num;

	num = va_arg(args, unsigned long);
	tmp = ft_itoa_x(num, st);
	for_str_f_x(st, tmp);
	free(tmp);
}
