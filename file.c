#include "monty.h"

/**
 * file_handle - function that handle file
 *
 * @file_name: The file Name
 */

void file_handle(char *file_name)
{
	FILE *fptr;

	/*open the file*/
	fptr = fopen(file_name, "r");
	if (fptr == NULL || !file_name)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	/*Read the file*/
	read_file(fptr);

	/*close The file*/
	fclose(fptr);
}

/**
 * read_file - function that extract the line from file
 *
 * @fptr: The File
 */

void read_file(FILE *fptr)
{
	int line;
	int type_ds = 0;
	char *buffer = NULL;
	size_t line_size;

	for (line = 1; getline(&buffer, &line_size, fptr) != -1; line++)
	{
		/*To take the opcode from buffer*/
		type_ds = parse_line(buffer, line, type_ds);
	}
	free(buffer);
}

/**
 * parse_line - function that tack line and extract the opcode
 *
 * @buffer: The line
 *
 * @type_ds: That detemine the type of ds if 0 it be stack
 * if 1 it be queue
 *
 * @line: The size of line
 *
 * Return: The type type data structre
 */

int parse_line(char *buffer, int line, int type_ds)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed,\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (type_ds);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	choose_op(opcode, value, line, type_ds);
	return (type_ds);
}

/**
 * choose_op - function That choose The right operation
 *
 * @opcode: The opcode
 *
 * @value: The Value That should you use
 *
 * @line: The line
 *
 * @type_ds: Type of DS
 */

void choose_op(char *opcode, char *value, int line, int type_ds)
{
	int i, error = 1;

	instruction_t operation[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"swap", swap},
		{"nop", nop},
		{"div", div_node},
		{"mul", mul_list},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, opcode) == 0)
		{
			execut(operation[i].f, opcode, value, line, type_ds);
			error = 0;
		}
	}
	if (error == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * execut - function that execute the operation
 *
 * @f: function pointer
 *
 * @opcode: char pointer
 *
 * @value: value of the number
 *
 * @line: The number of line
 *
 * @type_ds: stack or queue
 */

void execut(void (*f)(stack_t **stack, unsigned int line),
		char *opcode, char *value, int line, int type_ds)
{
	stack_t *new_node;

	int i, assign = 1;

	if (strcmp(opcode, "push") == 0)
	{
		/*Handle Negative*/
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			assign = -1;
		}

		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}

		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}

		new_node = create_node(atoi(value) * assign);
		if (type_ds == 0)
			(*f)(&new_node, line);
	}
	else
	{
		(*f)(&top, line);
	}
}
