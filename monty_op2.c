#include "monty.h"

/**
 * swap - function that swap first two node
 *
 * @stack: The pointer to linked list
 *
 * @line_number: The line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next == NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nop - function that do noting
 *
 * @stack: The pointer to linked list
 *
 * @line_number: The line Number
*/
