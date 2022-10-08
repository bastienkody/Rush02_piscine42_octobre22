#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"

char	**nbr_comp_to_strs(int t_nbr_len, t_number *t_nbr, t_dict *t_dico)
{
	char	**strs;
	int	word_nb;

	(void) t_dico;
	word_nb = wd_nb(t_nbr_len, t_nbr);
	strs = malloc((word_nb + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = strs_fulfill(t_nbr_len, *t_nbr, *t_dico);
	return(strs)//peut retourner un NULL attention dans le main
}



int		wd_nb(int t_nbr_len, t_number *t_nbr)
{
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	while (++i < t_nbr_len)
	{
		if (t_nbr[i].centaine[0] != '0')
			nb+= 2; //digit + "hundred"
		if (t_nbr[i].dizaine[0] == '1')
			nb+= 1; //teen : dizaine+unite==1word
		else
		{
 			if (t_nbr[i].dizaine[0] > '1')
				nb+= 1; //digit twenty to ninety"
			if (t_nbr[i].unite[0] != '0')
				nb+= 1;
			else if ( (nb == 0) && (i == t_nbr_len - 1))//print "zero" if nothing printed before and last triplet
				nb+= 1;
		}
		if (ft_strcmp(t_nbr[i].pos, "1"))//print pos if not last triplet
		{
			if (t_nbr[i].centaine[0] != '0' || t_nbr[i].dizaine[0] != '0' || t_nbr[i].unite[0] != '0')//if triplet != 000 
				nb+= 1;
		}
	}
	return (nb);
}
