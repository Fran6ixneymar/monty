#include "main.h"

/**
 * append_node - This adds a new node at the end of a stack
 * @head: Pointer that points to the stack
 * @n: value of the new node
 * Return: Pointer to the new node
 */
__stack_t *append_node(__stack_t **head, const int n)
{
	__stack_t *new = NULL, *current = NULL;

	new = malloc(sizeof(__stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(globe.stack, globe.file);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	new->prev = current;

	return (new);
}

/**
 * pop_node - This deletes the last node of a stack
 * @head: Pointer that points to the stack
 * Return: void
 */
void pop_node(__stack_t **head)
{
	__stack_t *current = NULL;

	if (*head == NULL)
		return;

	current = *head;
	while (current->next != NULL)
		current = current->next;

	if (current->prev != NULL)
		current->prev->next = NULL;
	else
		*head = NULL;

	free(current);
}

/**
 * unshift_node - This adds a new node at the beginning of a stack
 * @head: Pointer that points to the stack
 * @n: value of the new node
 * Return: Pointer to the new node
 */
__stack_t *unshift_node(__stack_t **head, const int n)
{
	__stack_t *new = NULL;

	new = malloc(sizeof(__stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(globe.stack, globe.file);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}
