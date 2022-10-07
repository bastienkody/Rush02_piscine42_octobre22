#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"


int	main(int argc, char *argv[])
{
	char	*pathname;
	char	*nbr_str;
	char	**res;

	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		pathname = "numbers.dict";
		nbr_str = argv[1];
	}
	else if (argc == 3)
	{
		pathname = argv[1];
		nbr_str = argv[2];
	}
	res = nbr_comp_to_strss(count_triplet(nbr_str), parse_number(char *str_nbr), parse(pathname));	
	if (!res)
		return (-2);
}
