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
	size_t line_number = 1;
	char *cmd = NULL;
	void (*ins_func)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	if (argc != 2)
		print_error_s("USAGE: monty file", "");

	while ((opcode = get_opcode(argv[1], line_number)) != NULL)
	{
		cmd = strtok(opcode, " \t\r\n");
		if (cmd == NULL || *cmd == '#')
		{
			line_number++;
			free(opcode);
			continue;
		}

		ins_func = get_ins_func(cmd);
		if (ins_func == NULL)
			line_error("unknown instruction ", line_number, cmd, stack);

		ins_func(&stack, line_number);

		free(opcode);
		line_number++;
	}

	free_stack(stack);

	return (0);
}
