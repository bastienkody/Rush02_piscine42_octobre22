#ifndef NUMBER_MGMT_H

# define NUMBER_MGMT_H

# include <stdlib.h>
# include <stdio.h>
# include "util_str.h"

typedef struct s_number
{
	char	centaine[2];
	char	dizaine[2];
	char	unite[2];
	char	*pos;
}	t_number;

char		*gen_pos(int i);
t_number	*t_nbr_z_fulfill(t_number *t_nbr, int nb_triplet);
t_number	*t_nbr_fulfill(t_number *t_nbr, char *str_nbr, int nb_triplet);
t_number	*parse_number(char *nbr);
void		print_t_number(t_number *t_nbr, int nb_triplet);
void		free_t_nbr(t_number *t_nbr, int t_nbr_len);

#endif
