#include "monty.h"

/**
 * create_node - function use to create a new node
 *
 * @data: The data of node
 *
 * Return: The pointer to node
 */
stack_t *create_node(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = data;

	return (new_node);
}
/**
 * push - push int to a stack
 * @new_node: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **new_node, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (top == NULL)
	{
		top = *new_node;
		return;
	}
	temp = top;
	top = *new_node;
	top->next = temp;
	temp->prev = top;
}

/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current_element;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	current_element = *stack;
	while (current_element != NULL)
	{
		fprintf(stdout, "%d\n", current_element->n);
		current_element = current_element->next;
	}
}

/**
 * pint - function that print the top of stack
 *
 * @stack: pointer to the linked list stack
 *
 * @line_number: number of line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - function that print the top of stack
 *
 * @stack: pointer to the linked list
 *
 * @line_number: number of line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
