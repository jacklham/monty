#include "monty.h"

/**
 * main - function for monty program
 * @argc: num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_handle(arv[1]);
	return (0);
}
