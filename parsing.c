#include "file_mgmt.h"

int	f_sizing(char *pathname)
{
	int		fd;
	int		counter;
	char	buf;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (fd);
	counter = 0;
	while (read(fd, &buf, 1))
		counter += 1;
	close(fd);
	return (counter);
}

char	*f_extracting(char *pathname)
{
	int		fd;
	char	*res;

	res = malloc((f_sizing(pathname) + 0) * sizeof(char));
	if (!res)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, res, f_sizing(pathname));
	close(fd);
	return (res);
}

int	count_lines(char *str)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i] == '\n')
		{
			if (str[i - 1] != '\n')
				counter++;
		}
		i++;
	}
	return (counter);
}

char	*parse_key(char *str)
{
	char	*res;
	int		i;

	while (!(*str >= '0' && *str <= '9'))
		str++;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < 1)
		return (NULL);
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*parse_value(char *str)
{
	char	*res;
	int		i;

	while (*str != ':')
			str++;
	str++;
	while (*str == ' ') // skip les premiers espaces avant value
		str++;
	i = 0;
	while (str[i] > 31 && str[i] < 127) // prend les espaces de value
		i++;
	if (i < 1)
		return (NULL);
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] > 31 && str[i] < 127)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	char	*str;

	str = f_extracting("numbers.dict");
	printf("str:%s\n", str);
	printf("lines :%d\n", count_lines(str));
	free(str);
	
}*/
