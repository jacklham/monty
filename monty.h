#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

/*Function to Handle file*/
void file_handle(char *file_name);
void read_file(FILE *fptr);
int parse_line(char *buffer, int line, int type_ds);

/*fucntions monty
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _print_string(stack_t **stk, unsigned int line_num);
void _rotate_left(stack_t **stack, unsigned int line_num);
void _rotate_right(stack_t **stack, unsigned int line_num);
*/

/**func maths
void subtractTopTwo(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void multiplyTopTwo(stack_t **stack, unsigned int line_number);
void divideTopTwo(stack_t **stack, unsigned int line_number);
void moduloTopTwo(stack_t **stack, unsigned int line_number);
*/

/**Utility functions
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

*Function to handle files
void file(char *the_file);
*/

#endif
