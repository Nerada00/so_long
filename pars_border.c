#include "so_long.h"

int     check_one(char *str)
{
        int     i;
        i = 0;
        while (str[i])
        {
        if (str[i] == '1')
                return (1);
        }
        return (0);
}

int	check_up_border(char *str)
{
        int     i;
        i = 0;
        while (str[i] != '\n' && check_one(str) == 1)
        {
                i++;
        }
        return (0);
}
int	check_side_border(void)
{
	
        return (0);
}
int	check_down_border(void)
{
        return (0);
}

int	all_border(void)
{
        return (0);
}