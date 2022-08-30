#include "monty.h"


/**
 * free_stack - Frees a stack_t list
 * @stack: stack_t list to free
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = NULL;

	while (stack != NULL)
	{
		current = stack;

		stack = stack->next;

		free(current);
	}
}
