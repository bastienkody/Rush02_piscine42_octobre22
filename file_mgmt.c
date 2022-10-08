#include "file_mgmt.h"
#include "util_str.h"

t_dict	*parser(char *pathname)
{
	char	*dict_str;
	int		lines;
	t_dict	*t_dico;

	dict_str = f_extracting(pathname);
	if (!dict_str)
		return (NULL);
	lines = count_lines(dict_str);
	if (!check_dict_str(dict_str, lines))
		return (NULL);
	t_dico = malloc((lines + 1) * sizeof(t_dict));
	if (!t_dico)
		return (NULL);
	t_dico = t_dico_fulfill(dict_str, t_dico);
	free(dict_str);
	return (t_dico - lines);
}

int	check_dict_str(char *dict_str, int lines)
{
	if (lines < 41)
	{
		ft_putstr("Dict_error (nb lines < 41)\n");
		return (0);
	}
	if (!check_column(dict_str))
	{
		ft_putstr("dict_error (':')\n");
			return (0);
	}
	return (1);
}

int	check_column(char *dict_str)
{
	int	i;
	int j;
	int	trigger;

	i = 0;
	while (dict_str[i])
	{
		if (dict_str[i] == '\n' && dict_str[i + 1] != '\n' && dict_str[i + 1] != '\0')
		{
			j = 1;
			trigger = 0;
			while (dict_str[i + j] != '\n' && dict_str[i + j] != '\n')
			{
				if (dict_str[i + j] == ':')
					trigger = 1;				
				j++;
			}
			if (!trigger)
				return (0);
		}
		i++;
	}
	return (1);
}

t_dict	*t_dico_fulfill(char *dict_str, t_dict *t_dico)
{
	while (*dict_str == '\n') //skip possible empty lines at beggining of file
		dict_str++;
	while (*dict_str)
	{
		t_dico->key = parse_key(dict_str);
		if (!t_dico->key)
			return (NULL);
		t_dico->value = parse_value(dict_str);
		if (!t_dico->value)
			return (NULL);
		while (*dict_str != '\n')
			dict_str++;
		while (*dict_str == '\n') //skip possible empty lines. 
			dict_str++;
		t_dico++;
	}
	t_dico->key = NULL;
	return (t_dico);
}

void	print_t_dict(t_dict *t_dico)
{
	while (t_dico->key)
	{
		ft_putstr(t_dico->key);
		ft_putchar('\n');
		ft_putstr(t_dico->value);
		ft_putchar('\n');
		t_dico++;
	}	
}

void	free_t_dict(t_dict *t_dico)
{
	int	i;

	i = 0;
	while (t_dico[i].key)
	{
		free(t_dico[i].key);
		free(t_dico[i].value);
		i++;
	}
	free(t_dico);
}

/*int	main(void)
{
	t_dict	*t_dico;

	t_dico = parser("numbers.dict2");
	if (!t_dico)
		return (-1);
	print_t_dict(t_dico);
	free_t_dict(t_dico);
	return (0);
	
}*/
