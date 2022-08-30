#include "monty.h"


void ins_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int n;
	char *num_token = NULL;

	num_token = strtok(NULL, " \t\r\n");
	if (num_token == NULL)
		line_error("usage: push integer", line_number, "", *stack);

	if (!strcmp(num_token, "0") || !strcmp(num_token, "-0"))
		n = 0;
	else
	{
		n = atoi(num_token);
		if (n == 0 || contains_letter(num_token))
			line_error("usage: push integer", line_number, "", *stack);
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
