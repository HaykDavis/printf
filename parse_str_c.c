#include "ft_printf.h"

void	parse_str_c(va_list args, t_printf *st)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = va_arg(args, int);
	if (!st->minus)
		while (st->vv-- > 1)
			st->length += write(1, " ", 1);
	st->length += write(1, &tmp, 1);
	if (st->minus)
		while (st->vv-- > 1)
			st->length += write(1, " ", 1);
}
