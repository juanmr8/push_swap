#include "push_swap.h"

void print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long ft_atol(char *str)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int main (int argc, char *argv[])
{
	int i;
	int j;
	int *numbers;
	long num;

	if (argc < 2)
		return (0);
	i = 1;

	// Validate input - all are numbers
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0') 
        	print_error_and_exit();
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				print_error_and_exit();
			j++;
		}
		i++;
	}

	// Parse numbers and store in array;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (1);
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free(numbers);
			print_error_and_exit();
		}
		numbers[i - 1] = num;
		i++;
 	}

	// Check dupes
	i = 0;
	while (i < argc -1)
	{
		int j = i + 1;
		while (j < argc - 1)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				print_error_and_exit();
			}
			j++;
		}
		i++;
	}
	write(1, "Valid", 5);
	free(numbers);
	return (0);
}
