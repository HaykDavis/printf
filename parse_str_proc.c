#include "ft_printf.h"

void	parse_str_proc(t_printf *st)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = '%';
	if (!st->minus && !st->zero)
		while (st->vv-- > 1)
			st->length += write(1, " ", 1);
	if (st->zero)
		while (st->vv-- > 1)
			st->length += write(1, "0", 1);
	st->length += write(1, &tmp, 1);
	if (st->minus)
		while (st->vv-- > 1)
			st->length += write(1, " ", 1);
}
