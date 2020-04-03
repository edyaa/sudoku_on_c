int		in_arr_for_row(int nb, int arr[9][9]);
int		in_arr_for_column(int nb, int arr[9][9][9], int y);
int		in_arr_for_square(int nb, int arr[9][9][9], int x, int y);

void	check_hidden_row(int numbers[9][9][9], int x, int arr[9][9])
{
	int j;
	int k;

	j = -1;
	while (++j < 9)
	{
		k = -1;
		while (numbers[x][j][++k] != 0)
			if(in_arr_for_row(numbers[x][j][k], numbers[x]) == 1)
				arr[x][j] = numbers[x][j][k];
	}
}

void	check_hidden_column(int numbers[9][9][9], int y, int arr[9][9])
{
	int i;
	int k;

	i = -1;
	while (++i < 9)
	{
		k = -1;
		while (numbers[i][y][++k] != 0)
			if(in_arr_for_column(numbers[i][y][k], numbers, y) == 1)
				arr[i][y] = numbers[i][y][k];
	}
}

void	check_hidden_square(int numbers[9][9][9], int arr[9][9])
{
	int i;
	int j;
	int k;

	i = -1;
	while(++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			k = -1;
			while (numbers[i][j][++k] != 0)
				if (in_arr_for_square(numbers[i][j][k], numbers, i, j) == 1)
					arr[i][j] = numbers[i][j][k];
		}
	}
}
