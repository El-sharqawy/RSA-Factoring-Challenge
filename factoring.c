#include <stdio.h>

/**
 * trial_division - factorize a number.
 * @buf: a number to be used
 *
 * Return: always 0 (Success)
 */
int trial_division(long int n)
{
	long int fNum;

	if (n % 2 == 0)
	{
		printf("%lu=%lu*%i\n", n, n / 2, 2);
		return (0);
	}

	fNum = 3;

	while (fNum * fNum <= n)
	{
		if (n % fNum == 0)
		{
			printf("%lu=%lu*%lu\n", n, n / fNum, fNum);
			return (0);
		}
		else
		{
			fNum += 2;
		}
	}

	printf("%lu=%lu*%i\n", n, n, 1);

	return (0);
}
