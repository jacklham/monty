#include "monty.h"

/**
 * pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0;

	(void)line_number;


	while (temp)
	{
		i = temp->n;
		if (i == 0 || isalpha(i) == 0)
			break;
		putchar(i);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack;


	int aux2 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux2 = iterator->n;

	while (iterator->next)
	{
		iterator = iterator->next;
		iterator->prev->n = iterator->n;
	}

	iterator->n = aux2;
}

/**
 * rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack;

	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (iterator->next)
		iterator = iterator->next;

	aux = iterator->n;

	while (iterator->prev)
	{
		iterator = iterator->prev;
		iterator->next->n = iterator->n;
	}

	iterator->n = aux;
}
