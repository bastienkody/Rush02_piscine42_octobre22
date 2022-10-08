#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"
int	check_args(char *pathname, char *nbr_str);

int	main(int argc, char *argv[])
{
	char	*pathname;
	char	*nbr_str;
	//char	**res;

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
	printf("args ok!\n");
	//res = nbr_comp_to_strss(count_triplet(nbr_str), parse_number(char *str_nbr), parse(pathname));	
	//if (!res)
	//	return (-3);
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
