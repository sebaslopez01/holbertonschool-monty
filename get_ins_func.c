#include "monty.h"


/**
 * get_ins_func - Selects the correct function to perform the instruction
 * asked
 * @instruction: Instruction to use
 *
 * Return: A pointer function that corresponds to the instruction given
 */
void (*get_ins_func(char *instruction))(stack_t **, unsigned int)
{
	size_t i = 0;
	instruction_t instructions[] = {
		{"push", ins_push},
		{"pall", ins_pall},
		{"pint", ins_pint},
		{NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (!strcmp(instructions[i].opcode, instruction))
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
