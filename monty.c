#include "monty.h"


char *opcode = NULL;


/**
 * main - Executes de commands of a monty file
 * @argc: Size of argv
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	ssize_t bytes_readed;
	size_t len = 0, line_number = 1;
	char *raw_opcode = NULL, *opcode_copy = NULL;
	void (*ins_func)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	if (argc != 2)
		print_error_s("USAGE: monty file", "");

	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
		print_error_s("Error: Can't open file ", argv[1]);

	while ((bytes_readed = getline(&raw_opcode, &len, monty_file)) != -1)
	{
		opcode = strdup(raw_opcode);
		opcode_copy = strtok(raw_opcode, " \t\r\n");
		if (opcode_copy == NULL)
		{
			line_number++;
			continue;
		}

		ins_func = get_ins_func(opcode_copy);
		if (ins_func == NULL)
			print_line_error("unknown instruction ", line_number, opcode_copy);

		ins_func(&stack, line_number);
		
		free(opcode);
		line_number++;
	}

	fclose(monty_file);
	if (opcode)
		free(opcode);
	free_stack(stack);

	return (0);
}
