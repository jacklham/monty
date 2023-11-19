#include "monty.h"

stack_t *top = NULL;
/**
 * main - function for monty program
 * @arc: num of arguments
 * @arv: opcode file
 * Return: 0
 */
int main(int arc, char **arv)
{
	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_handle(arv[1]);
	return (0);
}
