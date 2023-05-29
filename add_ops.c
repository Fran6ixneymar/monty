#include "main.h"

/**
 * f_mod - This computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_mod(__stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = mod;
}

/**
 * f_pchar - This at the top of the stack prints the char.
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_pchar(__stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(*stack, globe.file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * f_pstr - This starting at the top of the stack prints the string.
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_pstr(__stack_t **stack, unsigned int line_number)
{
	__stack_t *tmp = *stack;

	(void)line_number;

	while (tmp != NULL && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * f_rotl - This rotates the stack to the top
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_rotl(__stack_t **stack, unsigned int line_number)
{
	int n;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	n = (*stack)->n;
	f_pop(stack, line_number);
	append_node(stack, n);
}

/**
 * f_rotr - This rotates the stack to the bottom
 * @stack: Pointer that points to the stack
 * @line_number: line number
 * Return: void
 */
void f_rotr(__stack_t **stack, unsigned int line_number)
{
	__stack_t *tmp = *stack;
	int n;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	n = tmp->n;
	pop_node(stack);
	unshift_node(stack, n);
}
