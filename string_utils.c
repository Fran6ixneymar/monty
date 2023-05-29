#include "main.h"

/**
 * is_number - This checks if a string is a number
 * @str: The string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * free_stack - This frees a stack
 * @stack: Pointer that points to the stack
 * Return: void
 */
void free_stack(__stack_t *stack)
{
	__stack_t *current = stack;

	while (current != NULL)
	{
		current = current->next;
		free(stack);
		stack = current;
	}
}

/**
 * free_all - This frees a stack and a file
 * @stack: Pointer that points to the stack
 * @file: Pointer that points to the file
 * Return: void
 */
void free_all(__stack_t *stack, FILE *file)
{
	free_stack(stack);
	fclose(file);
}

/**
 * get_op_func - This selects the correct function to perform the operation
 * @s: The operator passed as argument
 * Return: Pointer that points to the function corresponding to the operator
 */
void (*get_op_func(char *s))(__stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"#", f_nop},
		{"", f_nop},
		{"\n", f_nop},
		{NULL, NULL}};
	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", globe.line_number, s);
	free_all(globe.stack, globe.file);
	exit(EXIT_FAILURE);
}

/**
 * split - This splits a string into tokens
 * @str: The string to be split
 * @delim: delimiter
 * Return: Pointer that points to an array of strings
 */
char **split(char *str, char *delim)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(globe.stack, globe.file);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		if (tokens[i][0] == '#')
		{
			tokens[i] = NULL;
			break;
		}
		i++;
	}

	return (tokens);
}
