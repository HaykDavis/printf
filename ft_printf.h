#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	int		zero;
	int		vv;
	int		minus;
	int		length;
	int		pr;
	int		dot;
	char	id;
}				t_printf;

int		ft_printf(const char *format, ...);

char	*ft_itoa(long n);
int		func_len(long i);
int		ft_types(char str);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *str);
int		func_len_x(unsigned int i);
char	*ft_itoa_u(unsigned int n);
int		func_len_u(unsigned int i);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa_p(unsigned long n);
int		func_len_p(unsigned long i);
void	parse_str_proc(t_printf *st);
void	for_str_f_u(t_printf *st, char *t);
void	for_str_f_p(t_printf *st, char *t);
void	for_str_f_x(t_printf *st, char *t);
char	*ft_memset(void *m, int s, size_t l);
void	for_str_s_x(t_printf *st, int w, int z);
void	for_str_s_u(t_printf *st, int w, int z);
void	for_str_s_p(t_printf *st, int w, int z);
void	parse_str_c(va_list args, t_printf *st);
void	parse_str_d(va_list args, t_printf *st);
void	parse_str_s(va_list args, t_printf *st);
void	parse_str_u(va_list args, t_printf *st);
void	parse_str_x(va_list args, t_printf *st);
void	parse_str_p(va_list args, t_printf *st);
char	*ft_itoa_x(unsigned int n, t_printf *st);
void	for_str_f_d(t_printf *st, char s, char *t);
void	*ft_calloc(size_t numelems, size_t sizelem);
void	for_str_s_d(t_printf *st, int s, int w, int z);
char	*ft_putnbr_char(long n, char *str, int masslen);
void	for_str_t_d(t_printf *st, int l, int w, char *t);
void	for_str_t_p(t_printf *st, int l, int w, char *t);
void	for_str_t_u(t_printf *st, int l, int w, char *t);
void	for_str_t_x(t_printf *st, int l, int w, char *t);
char	*ft_putnbr_char_X(unsigned int n, char *str, int masslen);
char	*ft_putnbr_char_x(unsigned int n, char *str, int masslen);
char	*ft_putnbr_char_u(unsigned int n, char *str, int masslen);
char	*ft_putnbr_char_p(unsigned long n, char *str, int masslen);
void	parse_str(const char *format, va_list args, t_printf *st, int *i);
void	ft_parse_types(const char *format, va_list args, t_printf *st, int **i);
void	ft_parse_flags(const char *format, va_list args, t_printf *st, int **i);

#endif