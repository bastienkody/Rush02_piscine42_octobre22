#include "util_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_strlen("salut"));
	printf("%i\n", ft_strcmp("a", ""));
	ft_putchar('a');
	ft_putstr("Salut!\n");
	return (0);
}*/
