#include "monty.h"

/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *new_element;
	(void)line_number;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_element->n = var_global.push_arg;
	new_element->next = *stack;
	new_element->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_element;
	*stack = new_element;
}

/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current_element;

	current_element = *stack;
	while (current_element != NULL)
	{
		printf("%d\n", current_element->n);
		current_element = current_element->next;
	}
}
