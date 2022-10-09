#include "file_mgmt.h"
#include "number_mgmt.h"
#include "util_str.h"
#include "comp_nbr.h"

char	**nbr_comp_to_strs(int t_nbr_len, t_number *t_nbr, t_dict *t_dico)
{
	char	**strs;
	int		word_nb;
	int		i;

	(void) t_dico;
	word_nb = wd_nb(t_nbr_len, t_nbr);
	strs = malloc((word_nb + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = strs_fulfill(strs, t_nbr_len, t_nbr, t_dico);
	//si un seul str de strs == NULL (sauf le dernier element) --> dict ne permet pas d'ecrire le nombre (print dans find_key)
	i = -1;
	while (++i < word_nb)
	{
		if (strs[i] == NULL)
			return (NULL);
	}
	free_t_nbr(t_nbr, t_nbr_len);
	free_t_dict(t_dico);
	return(strs);
}

//ne serait-ce pas plus court de faire : strs = find_centaine puis find_dizaine etc??
char	**strs_fulfill(char **strs, int t_nbr_len, t_number *t_nbr, t_dict *t_dico)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < t_nbr_len)
	{
		if (t_nbr[i].centaine[0] != '0')
		{
			strs[j++] = find_by_key(t_nbr[i].centaine, t_dico);					//digit centaine
			strs[j++] = find_by_key("100", t_dico);								//"hundred""
		}
		if (t_nbr[i].dizaine[0] == '1')
			strs[j++] = find_teen_by_key(t_nbr[i].dizaine, t_nbr[i].unite, t_dico);//teen (10 to 19)
		else
		{
 			if (t_nbr[i].dizaine[0] > '1')
				strs[j++] = find_dizaine_by_key(t_nbr[i].dizaine, t_dico); 		//dizaine (twenty to ninety)
			if (t_nbr[i].unite[0] != '0')
				strs[j++] = find_by_key(t_nbr[i].unite, t_dico);					//unite
			else if ( (j == 0) && (i == t_nbr_len - 1))
				strs[j++] = find_by_key(t_nbr[i].unite, t_dico);					//unite == nbr == zero
		}
		if (ft_strcmp(t_nbr[i].pos, "1"))
		{
			if (t_nbr[i].centaine[0] != '0' || t_nbr[i].dizaine[0] != '0' || t_nbr[i].unite[0] != '0')
				strs[j++] = find_by_key(t_nbr[i].pos, t_dico);						//pos
		}
	}	
	strs[j] = NULL;
	return (strs);
}

char	*find_by_key(char *key, t_dict *t_dico)
{
	while (t_dico->key)
	{
		if ( ! ft_strcmp(key, t_dico->key))
			return (ft_strdup(t_dico->value));
		t_dico++;
	}
	ft_putstr("Error (key not found in dict)\n");//if ft has not return yet then the key is for sure not found in dict
	return (NULL);
}

char	*find_dizaine_by_key(char *dizaine, t_dict *t_dico)
{
	char	nbr_y[3];

	nbr_y[0] = dizaine[0];
	nbr_y[1] = '0';
	nbr_y[2] = '\0';
	while (t_dico->key)
	{
		if ( ! ft_strcmp(nbr_y, t_dico->key))
			return (ft_strdup(t_dico->value));
		t_dico++;
	}
	ft_putstr("Error (key dizaine not found in dict)\n");
	return (NULL);
}

char	*find_teen_by_key(char *dizaine, char *unite,  t_dict *t_dico)
{
	char	teen[3];

	teen[0] = dizaine[0];
	teen[1] = unite[0];
	teen[2] = '\0';
	while (t_dico->key)
	{
		if ( ! ft_strcmp(teen, t_dico->key))
			return (ft_strdup(t_dico->value));
		t_dico++;
	}
	ft_putstr("Error (key teen not found in dict)\n");
	return (NULL);
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
