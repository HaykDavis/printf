#include "ft_printf.h"

void	parse_str(const char *format, va_list args, t_printf *st, int *i)
{
	int	len;

	len = st->length;
	ft_bzero(st, sizeof(t_printf));
	st->length = len;
	while (!ft_types(format[*i]) && format[*i] != '\0')
		ft_parse_flags(format, args, st, &i), (*i)++;
	if (st->vv < 0)
	{
		st->vv = st->vv * -1;
		st->minus = 1;
	}
	if (st->minus == 1)
		st->zero = 0;
	ft_parse_types(format, args, st, &i);
}

void	ft_parse_flags(const char *format, va_list args, t_printf *st, int **i)
{
	if (format[**i] == '-')
		st->minus = 1;
	if (format[**i] == '0' && !st->vv)
		st->zero = 1;
	if (format[**i] == '*' && st->dot != 1)
		st->vv = va_arg(args, int);
	if ((format[**i] >= '0' && format[**i] <= '9') && st->dot != 1)
		st->vv = st->vv * 10 + (format[**i] - '0');
	if (format[**i] == '.')
		st->dot = 1;
	if ((format[**i] >= '0' && format[**i] <= '9') && st->dot == 1)
		st->pr = st->pr * 10 + (format[**i] - '0');
	if (format[**i] == '*' && st->dot == 1)
		st->pr = va_arg(args, int);
}

void	ft_parse_types(const char *format, va_list args, t_printf *st, int **i)
{
	if (format[**i] == 's')
		parse_str_s(args, st);
	else if (format[**i] == 'c')
		parse_str_c(args, st);
	else if (format[**i] == 'u')
		parse_str_u(args, st);
	else if (format[**i] == 'p')
		parse_str_p(args, st);
	else if (format[**i] == 'x' || format[**i] == 'X')
	{
		if (format[**i] == 'x')
			st->id = 'x';
		else
			st->id = 'X';
		parse_str_x(args, st);
	}
	else if (format[**i] == 'd' || format[**i] == 'i')
		parse_str_d(args, st);
	else if (format[**i] == '%')
		parse_str_proc(st);
	else if (!ft_types(format[**i]))
		return ;
	(**i)++;
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	t_printf	*st;
	int			ret;

	i = 0;
	va_start (args, format);
	st = ft_calloc(sizeof(t_printf), 1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				st->length += write(1, &format[i++], 1);
			parse_str(format, args, st, &i);
		}
		else
			st->length += write(1, &format[i++], 1);
	}
	va_end(args);
	ret = st->length;
	free(st);
	return (ret);
}
