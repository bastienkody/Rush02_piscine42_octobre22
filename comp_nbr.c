#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"
#include "find_dict_ft.h"

char	**nbr_comp_to_strs(int t_nbr_len, t_number *t_nbr, t_dict *t_dico)
{
	char	**strs;
	int		word_nb;
	int		i;

	word_nb = wd_nb(t_nbr_len, t_nbr);
	strs = malloc((word_nb + 1) * sizeof(char *));
	if (!strs || !t_dico)
		return (NULL);
	strs = strs_ff(strs, t_nbr_len, t_nbr, t_dico);
	strs -= word_nb;
	i = -1;
	while (++i < word_nb)
	{
		if (strs[i] == NULL)
			return (NULL);
	}
	free_t_nbr(t_nbr, t_nbr_len);
	free_t_dict(t_dico);
	return (strs);
}

char	**strs_ff(char **strs, int t_nbr_len, t_number *t_nbr, t_dict *t_dico)
{
	int	i;

	i = -1;
	while (++i < t_nbr_len)
	{
		if (t_nbr[i].centaine[0] != '0')
			strs = find_centaine(strs, t_nbr[i].centaine, t_dico);
		if (t_nbr[i].dizaine[0] == '1')
			strs = find_teen(strs, t_nbr[i].dizaine, t_nbr[i].unite, t_dico);
		else
		{
			if (t_nbr[i].dizaine[0] > '1')
				strs = find_dizaine(strs, t_nbr[i].dizaine, t_dico);
			if (t_nbr[i].unite[0] != '0')
				strs = find_key(strs, t_nbr[i].unite, t_dico);
			else if ((wd_nb(t_nbr_len, t_nbr) == 1) && (i == t_nbr_len - 1))
				strs = find_key(strs, t_nbr[i].unite, t_dico);
		}
		if (ft_strcmp(t_nbr[i].pos, "1") && (t_nbr[i].centaine[0] != '0'
				|| t_nbr[i].dizaine[0] != '0' || t_nbr[i].unite[0] != '0'))
				strs = find_key(strs, t_nbr[i].pos, t_dico);
	}	
	*strs = NULL;
	return (strs);
}

int	wd_nb(int t_nbr_len, t_number *t_nbr)
{
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	while (++i < t_nbr_len)
	{
		if (t_nbr[i].centaine[0] != '0')
			nb += 2;
		if (t_nbr[i].dizaine[0] == '1')
			nb += 1;
		else
		{
			if (t_nbr[i].dizaine[0] > '1')
				nb += 1;
			if (t_nbr[i].unite[0] != '0')
				nb += 1;
			else if ((nb == 0) && (i == t_nbr_len - 1))
				nb += 1;
		}
		if (ft_strcmp(t_nbr[i].pos, "1") && (t_nbr[i].centaine[0] != '0'
				|| t_nbr[i].dizaine[0] != '0' || t_nbr[i].unite[0] != '0'))
				nb += 1;
	}
	return (nb);
}
