#include "monty.h"


/**
 * ins_add - Executes the add instruction (Adds the top two elements
 * of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't add, stack too short", line_number, "", *stack);

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;

	ins_pop(stack, line_number);
}


/**
 * ins_nop - Executes the nop instruction (Doesn't do anything)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_nop(stack_t **stack, unsigned int line_number)
{
	return;
}
