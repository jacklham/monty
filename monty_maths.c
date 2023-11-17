#include "monty.h"

/**
 * subtractTopTwo - subtracts the top element from the
 * second top element of the stack
 * @stack: pointer to the Monty stack
 * @lineNumber: line number of the opcode
 */
void subtractTopTwo(stack_t **stack, unsigned int lineNumber);
void subtractTopTwo(stack_t **stack, unsigned int lineNumber)
{
	stack_t *currentNode = *stack;
	int elementsCount = 0, subtractionResult = 0;

	if (currentNode == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	while (currentNode)
	{
		currentNode = currentNode->next;
		elementsCount++;
	}

	if (stack == NULL || (*stack)->next == NULL || elementsCount <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	subtractionResult = (*stack)->next->n - (*stack)->n;
	_nop(stack, lineNumber);

	(*stack)->n = subtractionResult;
}

/**
 * multiplyTopTwo - multiplies the top element with the
 * second top element of the stack
 * @stack: pointer to the Monty stack
 * @lineNumber: line number of the opcode
 */
void multiplyTopTwo(stack_t **stack, unsigned int lineNumber);
void multiplyTopTwo(stack_t **stack, unsigned int lineNumber)
{
	int auxiliaryValue;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		auxiliaryValue = (*stack)->n;
		_nop(stack, lineNumber);
		(*stack)->n *= auxiliaryValue;
	}
}

/**
 * divideTopTwo - divides the second top element
 * by the top element of the stack
 * @stack: pointer to the Monty stack
 * @lineNumber: line number of the opcode
 */
void divideTopTwo(stack_t **stack, unsigned int lineNumber);
void divideTopTwo(stack_t **stack, unsigned int lineNumber)
{
	int divisionResult = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lineNumber);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		divisionResult = (*stack)->n;
		_nop(stack, lineNumber);
		(*stack)->n /= divisionResult;
	}
}

/**
 * moduloTopTwo - calculates the modulo of the second
 * top element by the top element of the stack
 * @stack: pointer to the Monty stack
 * @lineNumber: line number of the opcode
 */
void moduloTopTwo(stack_t **stack, unsigned int lineNumber);
void moduloTopTwo(stack_t **stack, unsigned int lineNumber)
{
	int moduloResult = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lineNumber);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		moduloResult = (*stack)->n;
		(*stack)->n %= moduloResult;
		_nop(stack, lineNumber);
	}
}
