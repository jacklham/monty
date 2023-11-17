#include "monty.h"

/**
 * _print_string - mod top of stack by second top stack
 * @stk: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void _print_string(stack_t **stk, unsigned int line_num)
{
	stack_t *tmp = *stk;
	int character = 0;

	(void)line_num;

	while (tmp)
	{
		character = tmp->n;
		if (character == 0 || !_isalpha(character))
			break;
		putchar(character);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotate_left - mod top of stack by second top stack
 * @stk: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void _rotate_left(stack_t **stk, unsigned int line_num)
{
	stack_t *current = *stk;
	int aux_value = 0;

	if (!line_num || !stk || !*stk || !(*stk)->next)
		return;

	aux_value = current->n;

	while (current->next)
	{
		current = current->next;
		current->prev->n = current->n;
	}

	current->n = aux_value;
}

/**
 * _rotate_right - mod top of stack by second top stacks
 * @stk: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void _rotate_right(stack_t **stk, unsigned int line_num)
{
	stack_t *current = *stk;
	int aux_value = 0;

	if (!line_num || !stk || !*stk || !(*stk)->next)
		return;

	while (current->next)
		current = current->next;

	aux_value = current->n;

	while (current->prev)
	{
		current = current->prev;
		current->next->n = current->n;
	}

	current->n = aux_value;
}
