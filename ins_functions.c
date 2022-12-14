#include "monty.h"

/**
 * ins_push - Executes the push instruction (Pushes an element
 * to the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
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


/**
 * ins_pall - Executes pall instruction (prints all the values
 * on the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 */
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


/**
 * ins_pint - Executes pint instruction (prints the value at the top
 * of the stack, followed by a new line)
 * @stack: stack_t list
 * @line_number: Current line number
 */
void ins_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		line_error("can't pint, stack empty", line_number, "", *stack);

	printf("%d\n", (*stack)->n);
}


/**
 * ins_pop - Executes pop instruction (Removes the top element
 * of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 */
void ins_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_node = NULL;

	if (stack == NULL || *stack == NULL)
		line_error("can't pop an empty stack", line_number, "", *stack);

	delete_node = *stack;

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(delete_node);
}


/**
 * ins_swap - Executes swap instruction (Swaps the top two elements
 * of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 */
void ins_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't swap, stack too short", line_number, "", *stack);

	next_node = (*stack)->next;

	(*stack)->next = next_node->next;
	(*stack)->prev = next_node;
	next_node->next = (*stack);
	next_node->prev = NULL;

	*stack = next_node;
}
