#ifndef FILE_MGMT_H
# define FILE_MGMT_H
 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		f_sizing(char *pathname);
char	*f_extracting(char *pathname);
int		count_lines(char *str);
char	*parse_key(char *str);
char	*parse_value(char *str);
t_dict	*parser(char *pathname);
char	*find_by_key(char *key, t_dict *t_dico);
void	print_t_dict(t_dict *t_dico);

#endif

// AJOUT necessaire d'une focntion qui vérifie les entrées du dict, une fois qu'il est parsé disons
