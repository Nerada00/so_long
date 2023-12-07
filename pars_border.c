
int map_readable(int fd)
{

}

int	check_up_border(int str)
{
    int i;

    i = 0;
    while (str[i][0] != '\n')
    {
        if (str[i][0] == 1)
        {
            i++;
            if (str[i][0] == '\n')
            {
                return (1);
            }
        }
        else
            return (0)
    }

}
int	check_side_border()
{

}
int	check_down_border()
{

}

int all_border()
{

}