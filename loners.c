int		check_rows(int arr[9][9], int x, int nb);
int		check_column(int arr[9][9], int y, int nb);
int		check_square(int arr[9][9], int x, int y, int nb);

void	solver(int arr[9][9])
{
	int numbers[9];
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
			if(arr[i][j] == 0)
			{
				count = 0;
				while (++k < 10)
					if(check_square(arr, i, j, k) && \
							check_rows(arr, i,  k) && check_column(arr, j, k))
						numbers[count++] = k;
				if (count == 1)
					arr[i][j] = numbers[0];
			}	
		}
	}
}
