#include "monty.h"


void ins_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *opcode_val = NULL;
	int n;

	if (stack == NULL)
		return;

	opcode_val = strtok(opcode, " \t\r\n");
	opcode_val = strtok(NULL, " \t\r\n");
	if (opcode_val == NULL)
		print_line_error("usage: push integer", line_number, "");
	if (*opcode_val == '0')
		n = 0;
	else
	{
		n = atoi(opcode_val);
		if (n == 0)
			print_line_error("usage: push integer", line_number, "");
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		print_error_s("Error: malloc failed", "");
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}


void ins_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = NULL;

	if (stack == NULL || *stack == NULL)
		return;
	
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);

		current = current->next;
	}
}
