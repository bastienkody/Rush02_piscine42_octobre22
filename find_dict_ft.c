#include "find_dict_ft.h"

char	**find_key(char **strs, char *key, t_dict *t_dico)
{
	while (t_dico->key)
	{
		if (!ft_strcmp(key, t_dico->key))
		{
			*strs++ = ft_strdup(t_dico->value);
			return (strs);
		}
		t_dico++;
	}
	ft_putstr("Error (key not found in dict)\n");
	return (NULL);
}

char	**find_centaine(char **strs, char *key, t_dict *t_dico)
{
	int	i;

	i = -1;
	while (t_dico[++i].key)
	{
		if (!ft_strcmp(key, t_dico[i].key))
			*strs++ = ft_strdup(t_dico[i].value);
	}
	i = -1;
	while (t_dico[++i].key)
	{
		if (!ft_strcmp("100", t_dico[i].key))
		{
			*strs++ = ft_strdup(t_dico[i].value);
			return (strs);
		}
	}
	ft_putstr("Error (key not found in dict)\n");
	return (NULL);
}

char	**find_dizaine(char **strs, char *dizaine, t_dict *t_dico)
{
	char	nbr_y[3];

	nbr_y[0] = dizaine[0];
	nbr_y[1] = '0';
	nbr_y[2] = '\0';
	while (t_dico->key)
	{
		if (!ft_strcmp(nbr_y, t_dico->key))
		{
			*strs++ = ft_strdup(t_dico->value);
			return (strs);
		}
		t_dico++;
	}
	ft_putstr("Error (key dizaine not found in dict)\n");
	return (NULL);
}

char	**find_teen(char **strs, char *dizaine, char *unite, t_dict *t_dico)
{
	char	teen[3];

	teen[0] = dizaine[0];
	teen[1] = unite[0];
	teen[2] = '\0';
	while (t_dico->key)
	{
		if (!ft_strcmp(teen, t_dico->key))
		{
			*strs++ = ft_strdup(t_dico->value);
			return (strs);
		}
		t_dico++;
	}
	ft_putstr("Error (key teen not found in dict)\n");
	return (NULL);
}
