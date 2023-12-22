#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main -  entry point
 *
 * Description: A function that print factors.
 * @ac: counter
 * @av: vector
 *
 * Return: 0 in success
 */
int main(int ac, char **av)
{
	FILE *file;
	size_t size;
	char *data = NULL;
	long long int n;
	long int i, n2;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&data, &size, file) != -1)
	{
		n = atoll(data);
		for (i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				n2 = n / i;
				printf("%lld=%ld*%ld\n", n, n2, i);
				break;
			}
		}
	}
	return (0);
}
