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
 * ins_sub - Executes the sub instruction (Subtracts the top two elements
 * of the stack from the second top element of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't sub, stack too short", line_number, "", *stack);

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	ins_pop(stack, line_number);
}


/**
 * ins_div - Executes the div instruction (Divides the second top element
 * of the stack by the top element of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't div, stack too short", line_number, "", *stack);

	if ((*stack)->n == 0)
		line_error("division by zero", line_number, "", *stack);

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;

	ins_pop(stack, line_number);
}


/**
 * ins_mod - Executes the mod instruction (Computes the rest of the division
 * of the second top element of the stack by the top element of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't mod, stack too short", line_number, "", *stack);

	if ((*stack)->n == 0)
		line_error("division by zero", line_number, "", *stack);

	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;

	ins_pop(stack, line_number);
}


/**
 * ins_mul - Executes the mul instruction (Multiplies the second top
 * element of the stack with the top element of the stack)
 * @stack: stack_t list
 * @line_number: Current line number
 *
 * Return: void
 */
void ins_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		line_error("can't mul, stack too short", line_number, "", *stack);

	result = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = result;

	ins_pop(stack, line_number);
}
