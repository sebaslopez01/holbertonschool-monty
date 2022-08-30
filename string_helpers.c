#include "monty.h"


int contains_letter(const char *str)
{
	size_t i;

	if (*str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}

	return (0);
}
