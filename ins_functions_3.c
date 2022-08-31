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
