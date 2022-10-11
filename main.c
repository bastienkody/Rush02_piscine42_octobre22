#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"

int		check_args(char *pathname, char *nbr);
int		ct_tpl(char *nbr);
void	print_strs(char **strs);
void	free_strs(char **strs);

int	main(int argc, char *argv[])
{
	char	*path;
	char	*nbr;
	char	**res;

	if (argc < 2 || argc > 3)
		return (-1);
	if (argc == 2)
	{
		path = "numbers.dict";
		nbr = argv[1];
	}
	else
	{
		path = argv[1];
		nbr = argv[2];
	}
	if (check_args(path, nbr))
		return (-2);
	res = nbr_comp_to_strs(ct_tpl(nbr), parse_number(nbr), parser(path));
	if (!res)
		return (-3);
	print_strs(res);
	free_strs(res);
	return (0);
}

int	check_args(char *pathname, char *nbr)
{
	if (f_sizing(pathname) < 1)
	{
		ft_putstr("Error (cant open file or empty file)\n");
		return (-1);
	}
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
		{
			ft_putstr("Error (number given is not a positive integer)\n");
			return (-1);
		}
		nbr++;
	}
	return (0);
}

void	print_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		ft_putstr(strs[i]);
		if (strs[i + 1] != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	ct_tpl(char *nbr)
{
	if (ft_strlen(nbr) % 3)
		return (ft_strlen(nbr) / 3 + 1);
	else
		return (ft_strlen(nbr) / 3);
}
