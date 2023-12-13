#include "so_long.h"

int	check_up_border(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
int	check_side_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	int dernierchar = ft_strlen(data->map[j]) - 1;
	while (data->map[i])
	{
		if (data->map[i][j] != '1' || data->map[i][dernierchar] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	check_down_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
		i++;
	i--;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_len_line(t_data *data)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	all_check(t_data *data)
{
	if (check_len_line(data) == 1 && check_up_border(data) == 1
		&& check_side_border(data) == 1 && check_down_border(data) == 1
		&& check_item(data) == 1 && check_exit(data) == 1 && check_spawn(data) == 1
		&& check_others(data) == 1)
		return (1);
	else
		return (0);
}