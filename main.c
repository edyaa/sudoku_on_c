#include <unistd.h>

int		sum(int arr[9][9]);
void	solver(int arr[9][9]);
int		ft_putchar(char c);
void	solve_for_hidden(int arr[9][9]);

void	ft_print(int arr[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(arr[i][j] + '0');
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		check_on_error(int arr[9][9])
{
	int check;

	while (sum(arr) != 405)
	{
		check = sum(arr);
		solver(arr);
		solve_for_hidden(arr);
		if (check == sum(arr))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	int sud[9][9];

	i = 0;
	while (++i < argc && argc == 10)
	{
		j = 0;
		while (argv[i][j] && j < 9)
		{
			if (argv[i][j] != '.')
				sud[i - 1][j] = argv[i][j] - '0';
			else
				sud[i - 1][j] = 0;
			j++;
		}
	}
	if (check_on_error(sud) == 1)
		ft_print(sud);
	else
		write(1, "Error\n", 6);
}
