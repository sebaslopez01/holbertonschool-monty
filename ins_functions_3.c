#include "monty.h"


/**
 * ins_nop - Executes the nop instruction (Doesn't do anything)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * ins_pchar - Executes the pchar instruction (Prints the char at the top
 * of the stack, followed by a new line)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
		line_error("can't pchar, stack empty", line_number, "", *stack);

	n = (*stack)->n;

	if (n < 0 || n > 127)
		line_error("can't pchar, value out of range", line_number, "", *stack);

	printf("%c\n", n);
}


/**
 * ins_pstr - Executes the pstr instruction (Prints the string starting at
 * at the top of the stack, followed by a new line)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = NULL;
	int n;

	if (stack == NULL || *stack == NULL)
	{
		putchar('\n');
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		n = current->n;

		if (n <= 0 || n > 127)
			break;

		putchar(n);

		current = current->next;
	}

	putchar('\n');
}


/**
 * ins_rotl - Executes the rotl instruction (Rotates the stack to the top)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = NULL, *next_node = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	next_node = (*stack)->next;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;

	next_node->prev = NULL;

	*stack = next_node;
}


/**
 * ins_rotr - Executes the rotr instruction (Rotates the stack to the bottom)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	(*stack)->prev = current;
	current->next = *stack;
	current->prev->next = NULL;
	current->prev = NULL;

	*stack = current;
}
