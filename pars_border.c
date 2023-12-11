#include "so_long.h"

int	check_up_border(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
int	check_side_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][j] != '1' || map[i][ft_strlen(map[j]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	check_down_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_len_line(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	all_check(char **map)
{
	if (check_up_border(map) == 1 && check_side_border(map) == 1
		&& check_down_border(map) == 1 && check_len_line(map) == 1
		&& check_item(map) == 1 && check_exit(map) == 1 && check_spawn(map) == 1
		&& check_others(map) == 1)
		return (1);
	else
		return (0);
}