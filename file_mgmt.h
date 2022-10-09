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
int	check_column(char *dict_str);
int	check_dict_str(char *dict_str, int lines);
t_dict	*t_dico_fulfill(char *dict_str, t_dict *t_dico);
t_dict	*parser(char *pathname);
char	*find_by_key(char *key, t_dict *t_dico);
void	print_t_dict(t_dict *t_dico);
void	free_t_dict(t_dict *t_dico);

#endif
