#include <unistd.h>

int		check_column(int arr[9][9], int y, int nb)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (arr[i][y] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		check_rows(int arr[9][9], int x,  int nb)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (arr[x][j] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		check_square(int arr[9][9], int x, int y, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (arr[i + x - x % 3][j + y - y % 3] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		sum(int arr[9][9])
{
	int sum;
	int i;
	int j;

	sum = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			sum += arr[i][j];
			j++;
		}
		i++;
	}
	return (sum);
}
