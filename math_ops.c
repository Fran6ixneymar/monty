#include "main.h"

/**
 * f_add - This adds the top two elements of the stack
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_add(__stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	f_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * f_nop - This operation does nothing
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_nop(__stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * f_sub - This from the top element subtracts the second top element of the stack.
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_sub(__stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * f_div - This divides the top element of the stack by the second top element
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_div(__stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * f_mul - This multiplies the top element of the stack with the second top element
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_mul(__stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->n * (*stack)->next->n;
	f_pop(stack, line_number);
	(*stack)->n = mul;
}
