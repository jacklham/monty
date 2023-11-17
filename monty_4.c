#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer to lists for monty stack.
 * @line_number: number of line opcode occurs.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int _sum = 0, m = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		m++;
	}

	if (stack == NULL || (*stack)->next == NULL || m <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	_sum = (*stack)->next->n + (*stack)->n;
	_nop(stack, line_number);

	(*stack)->n = _sum;
}

/**
 * _nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _isalpha - checks if integer is in alphabet
 * @v: integer
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int v)
{
	if ((v >= 97 && v <= 122) || (v >= 65 && v <= 90))
		return (1);
	else
		return (0);
}
