#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	z;

	c = (char *) s;
	z = 0;
	while (z < n)
	{
		c[z] = '\0';
		z++;
	}
}

void	*ft_calloc(size_t numelems, size_t sizelem)
{
	char	*memory;

	memory = malloc(sizelem * numelems);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, sizelem * numelems);
	return ((void *) memory);
}

char	*ft_memset(void *m, int s, size_t l)
{
	size_t			z;
	unsigned char	*o;

	o = (unsigned char *) m;
	z = 0;
	while (z < l)
	{
		o[z] = s;
		z++;
	}
	return ((void *) m);
}

char	*ft_strdup(char *str)
{
	char	*dubl;
	int		i;

	if (!str)
		return (NULL);
	dubl = (char *)malloc(sizeof(*dubl) * ft_strlen(str) + 1);
	if (!dubl)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dubl[i] = str[i];
		i++;
	}
	dubl[i] = '\0';
	return (dubl);
}
