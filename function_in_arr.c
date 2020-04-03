int		in_arr_for_row(int nb, int arr[9][9])
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			if (nb == arr[i][j])
				count++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		in_arr_for_column(int nb, int arr[9][9][9], int y)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			if (nb == arr[i][y][j])
				count++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		in_arr_for_square(int nb, int arr[9][9][9], int x, int y)
{
	int i;
	int j;
	int k;
	int count;

	i = -1;
	count = 0;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 9)
				if (arr[i + x - x % 3][j + y - y % 3][k] == nb)
					count++;
		}
	}
	if (count == 1)
		return (1);
	return (0);
}
