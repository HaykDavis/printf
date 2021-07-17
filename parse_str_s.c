#include "ft_printf.h"

void	parse_str_s(va_list args, t_printf *st)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	tmp = va_arg(args, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (st->dot && st->pr < (int)ft_strlen(tmp) && st->pr >= 0 && st->vv >= 0)
		len = st->pr;
	else
		len = (int)ft_strlen(tmp);
	if (!st->minus && !st->zero)
		while (st->vv-- > len)
			st->length += write(1, " ", 1);
	if (st->zero)
		while (st->vv-- > len)
			st->length += write(1, "0", 1);
	while (i < len)
		st->length += write(1, &tmp[i++], 1);
	if (st->minus)
		while (st->vv-- > len)
			st->length += write(1, " ", 1);
}
