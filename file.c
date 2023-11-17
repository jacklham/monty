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
 * parse_file - function that tack line and extract the opcode
 *
 * @buffer: The line
 *
 * @type_ds: That detemine the type of ds if 0 it be stack
 * if 1 it be queue
 *
 * @line_size: The size of line
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

	run_opcode(opcode, value, line, type_ds);
	return (type_ds);
}

/**
 * run_opcode - function to run the opcode
 *
 * @value: The element which we use in stack
 *
 * @line: The line of instruction
 *
 * @type_ds: if 0 use stack and if 1 use queue
 * */
void run_opcode(char *opcode, char *value, int line, int type_ds)
{
}
