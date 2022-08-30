#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>


/* Global Variables */

extern char *opcode;

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Prototypes */

void print_error_s(const char *msg, const char *arg);
void line_error(char *msg, size_t line_number, char *arg, stack_t *stack);
void free_stack(stack_t *stack);
void (*get_ins_func(char *instruction))(stack_t **, unsigned int);
void ins_push(stack_t **stack, unsigned int line_number);
void ins_pall(stack_t **stack, unsigned int line_number);
void ins_pint(stack_t **stack, unsigned int line_number);
void ins_pop(stack_t **stack, unsigned int line_number);
void ins_swap(stack_t **stack, unsigned int line_number);
void ins_add(stack_t **stack, unsigned int line_number);
void ins_nop(stack_t **stack, unsigned int line_number);
int contains_letter(const char *str);
char *get_opcode(const char *filename, size_t line_number);

#endif /* MONTY_H */
