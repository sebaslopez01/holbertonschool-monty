#include "monty.h"

/**
 * get_opcode - Gets the opcode from a monty file at a certain line
 * @filename: Monty file to get the opcode
 * @line_number: Line number to get the opcode from
 *
 * Return: A pointer to the opcode at the certain line number
 */
char *get_opcode(const char *filename, size_t line_number)
{
	FILE *monty_file;
	ssize_t readed_bytes = 0;
	size_t i, len = 0;
	char *local_opcode = NULL;

	monty_file = fopen(filename, "r");
	if (monty_file == NULL)
		print_error_s("Error: Can't open file ", filename);

	for (i = 0; i < line_number; i++)
	{
		readed_bytes = getline(&local_opcode, &len, monty_file);
		if (readed_bytes == -1)
			break;

		if (i == line_number - 1)
		{
			fclose(monty_file);
			return (local_opcode);
		}
	}

	fclose(monty_file);
	free(local_opcode);

	return (NULL);
}

