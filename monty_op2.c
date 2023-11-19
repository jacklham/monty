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
void nop(
		__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{}

/**
 * div_node - function that div the second top element by top element
 *
 * @stack: the pointer linked list
 *
 * @line_number: The line number
*/
void div_node(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_list - function that mul two element
 *
 * @stack: the pointer linked list
 *
 * @line_number: The line number
*/
void mul_list(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: mul by zero", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
