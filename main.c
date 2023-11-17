#include "monty.h"
global_var var_global;
/**
 * main - function for monty program
 * @arc: num of arguments
 * @arv: opcode file
 * Return: 0
 */
int main(int arc, char **arv)
{
	stack_t *stack;

	stack = NULL;
	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(arv[1], &stack);
	free_dlistint(stack);
	return (0);
}
