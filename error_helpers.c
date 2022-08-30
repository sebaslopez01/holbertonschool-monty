#include "monty.h"


/**
 * print_error_s - Prints an error message with a string and exit with a code
 * @msg: Error message
 * @arg: Argument to be passed of type char *
 *
 * Return: void
 */
void print_error_s(const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, arg);

	exit(EXIT_FAILURE);
}


/**
 * print_line_error - Prints an error with a number and a string
 * @msg: Error message
 * @line_number: Line number to print
 * @arg: String to be printed
 *
 * Return: void
 */
void line_error(char *msg, size_t line_number, char *arg, stack_t *stack)
{
	dprintf(STDERR_FILENO, "L%ld: %s%s\n", line_number, msg, arg);
	
	free(opcode);
	free_stack(stack);

	exit(EXIT_FAILURE);
}
