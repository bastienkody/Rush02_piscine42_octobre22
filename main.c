#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"
int	check_args(char *pathname, char *nbr_str);
void	free_strs(char **strs);

int	main(int argc, char *argv[])
{
	char	*pathname;
	char	*nbr_str;
	char	**res;
	int		i;

	if (argc < 2 || argc > 3)
		return (-1);
	if (argc == 2)
	{
		pathname = "numbers.dict";
		nbr_str = argv[1];
	}
	else 
	{
		pathname = argv[1];
		nbr_str = argv[2];
	}
	if (check_args(pathname, nbr_str))
		return (-2);
	res = nbr_comp_to_strs(count_triplet(nbr_str), parse_number(nbr_str), parser(pathname));	
	if (!res)
		return (-3);
	i = -1;
	while (res[++i])
	{
		ft_putstr(res[i]);
		if (res[i + 1] != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	free_strs(res);
	return (0);
}

int	check_args(char *pathname, char *nbr_str)
{
	if (f_sizing(pathname) < 1)
	{
		ft_putstr("Error (cant open file or empty file)\n");
		return (-1);//unvalid pathname (fd<0) or file with no bytes (counter=0)
	}
	while (*nbr_str)
	{
		if (!(*nbr_str >= '0' && *nbr_str <= '9'))
		{
			ft_putstr("Error (number given is not a positive integer)\n");
			return (-1);
		}
		nbr_str++;
	}
	return (0);
}

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}
