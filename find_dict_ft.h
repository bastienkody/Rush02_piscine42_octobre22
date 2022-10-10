#ifndef FIND_DICT_FT_H
# define FIND_DICT_FT_H

# include "util_str.h"
# include "file_mgmt.h"

char	**find_key(char **strs, char *key, t_dict *t_dico);
char	**find_centaine(char **strs, char *key, t_dict *t_dico);
char	**find_dizaine(char **strs, char *dizaine, t_dict *t_dico);
char	**find_teen(char **strs, char *dizaine, char *unite, t_dict *t_dico);

#endif
