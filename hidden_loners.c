int     check_rows(int arr[9][9], int x, int nb);
int     check_column(int arr[9][9], int y, int nb);
int     check_square(int arr[9][9], int x, int y, int nb);
void	check_hidden_row(int numbers[9][9][9], int x, int arr[9][9]);
void	check_hidden_column(int numbers[9][9][9], int y, int arr[9][9]);
void	check_hidden_square(int numbers[9][9][9], int arr[9][9]);

void	loners(int arr[9][9], int numbers[9][9][9])
{
	int count;
	int k;
	int i;
	int j;

    i = -1;
    while (++i < 9)
    {
		j = -1;
		while (++j < 9)
		{
			k = 0;
			count = 0;
			if(arr[i][j] == 0)
			{
				while (++k < 10)
					if(check_square(arr, i, j, k) && \
							check_rows(arr, i,  k) && check_column(arr, j, k))
						numbers[i][j][count++] = k;
				numbers[i][j][count] = 0;
			}
		}
	}
}

void	pars(int arr[9][9], int numbers[9][9][9])
{
	int count;
	int i;
	int j;

	loners(arr, numbers);
	i = -1;
	while(++i < 9)
	{
		j = -1;
		while(++j < 9)
		{
			count = 0;
			if (arr[i][j] == 0)
				while (numbers[i][j][count] != 0)
					count++;
			else
				numbers[i][j][count] = arr[i][j];
			while (++count < 9)
				numbers[i][j][count] = 0;
		}
	}
}

void	solve_for_hidden(int arr[9][9])
{
	int numbers[9][9][9];
	int i;
	int j;

	pars(arr, numbers);
	i = -1;
	while(++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (numbers[i][j][1] != 0)
			{
				check_hidden_row(numbers, i, arr);
				check_hidden_column(numbers, j, arr);
				check_hidden_square(numbers, arr);
			}
		}
	}
}
