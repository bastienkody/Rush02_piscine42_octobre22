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
	t_dico = malloc((lines + 1) * sizeof(t_dict));
	if (!t_dico)
		return (NULL);
	t_dico = t_dico_fulfill(dict_str, t_dico);
	free(dict_str);
	return (t_dico - lines);
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

int	main(void)
{
	t_dict	*t_dico;

	t_dico = parser("numbers.dict2");
	if (!t_dico)
		return (-1);
	print_t_dict(t_dico);
	free_t_dict(t_dico);
	return (0);
	
}
