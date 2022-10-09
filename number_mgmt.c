#include "number_mgmt.h"

t_number	*parse_number(char *str_nbr)
{
	t_number	*t_nbr;
	int			nb_triplet;

	nb_triplet = count_triplet(str_nbr);
	t_nbr = malloc((nb_triplet) * sizeof(t_number));
	if (!t_nbr)
		return (NULL);
	t_nbr = t_nbr_z_fulfill(t_nbr, nb_triplet);
	t_nbr = t_nbr_fulfill(t_nbr, str_nbr, nb_triplet);
	//print_t_number(t_nbr, nb_triplet);
	return (t_nbr);
}

t_number	*t_nbr_z_fulfill(t_number *t_nbr, int nb_triplet)
{
	int	i;

	i = -1;
	while (++i < nb_triplet)
	{
		t_nbr[i].centaine[0] = '0';
		t_nbr[i].centaine[1] = '\0';
		t_nbr[i].dizaine[0] = '0';
		t_nbr[i].dizaine[1] = '\0';
		t_nbr[i].unite[0] = '0';
		t_nbr[i].unite[1] = '\0';
	}
	return (t_nbr);
}

t_number	*t_nbr_fulfill(t_number *t_nbr, char *str_nbr, int nb_triplet)
{
	int	i;
	int str_len;

	i = nb_triplet;
	str_len = ft_strlen(str_nbr);
	while (--i >= 0)
	{
		t_nbr[i].pos = gen_pos(nb_triplet - 1 - i);
		if (!t_nbr[i].pos)
			return (NULL);
		t_nbr[i].unite[0] = str_nbr[--str_len]; 
		if (--str_len > -1) 
			t_nbr[i].dizaine[0] = str_nbr[str_len]; 
		if (--str_len > -1) 
			t_nbr[i].centaine[0] = str_nbr[str_len]; 
	}
	return (t_nbr);
}

char	*gen_pos(int i)
{
	char	*pos;
	int		j;

	pos = malloc((2 + 3 * i) * sizeof(char));
	if (!pos)
		return (NULL);
	j = 0;
	pos[j] = '1';
	while (++j <= (i * 3))
		pos[j] = '0';
	pos[j] = '\0';
	return (pos);
}

void	print_t_number(t_number *t_nbr, int nb_triplet)
{
	int	i;

	i = -1;
	while (++i < nb_triplet)
		printf("cent:%s,diz:%s,unit:%s,pos:%s\n", t_nbr[i].centaine ,t_nbr[i].dizaine, t_nbr[i].unite, t_nbr[i].pos);
}

int	count_triplet(char *str_nbr)
{
	if (ft_strlen(str_nbr) % 3)
		return ((ft_strlen(str_nbr) / 3) + 1);
	else
		return (ft_strlen(str_nbr) / 3);
}

void	free_t_nbr(t_number *t_nbr, int t_nbr_len)
{
	int	i;

	i = -1;
	while (++i < t_nbr_len)
		free(t_nbr[i].pos);
	free(t_nbr);

}

/*int	main(void)
{
	parse_number("123456789");
}*/
