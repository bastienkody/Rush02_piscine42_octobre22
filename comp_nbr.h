#ifndef COMP_NBR_H
# define COMP_NBR_H

char	**nbr_comp_to_strs(int t_nbr_len, t_number *t_nbr, t_dict *t_dico);
char	**strs_fulfill(char **strs, int t_nbr_len, t_number *t_nbr, t_dict *t_dico);
char	*find_by_key(char *key, t_dict *t_dico);
char	*find_dizaine_by_key(char *dizaine, t_dict *t_dico);
char	*find_teen_by_key(char *dizaine, char *unite,  t_dict *t_dico);
int		wd_nb(int t_nbr_len, t_number *t_nbr);

#endif
