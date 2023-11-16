#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: The argument count
 *
 * @argv: The array of argument
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
