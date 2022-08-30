#include "monty.h"


/**
 * contains_letter - Verifies if a string contains a character
 * different to a number
 * @str: String to verify
 *
 * Return: 1 if it contains a letter, 0 otherwise
 */
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
