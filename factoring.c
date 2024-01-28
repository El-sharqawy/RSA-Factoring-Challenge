#include "factoring.h"

/**
 * factoring - factorize a number.
 * @buf: a pointer to the number
 *
 * Return: always 0 (Success)
 */
int factoring(char *buf)
{
	unsigned int i;
	unsigned int num;

	num = atoi(buf);

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, num / i, i);
			break;
		}
	}
	return (0);
}
