#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: pointer to the previous element of the stack (or queue)
 * @next: pointer to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} __stack_t;

/* Stack functions */
__stack_t *unshift_node(__stack_t **head, const int n);
void pop_node(__stack_t **head);
__stack_t *append_node(__stack_t **head, const int n);

/**
 * struct queue_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: pointer to the previous element of the stack (or queue)
 * @next: pointer to the next element of the stack (or queue)
 * @is_stack: 1 if stack, 0 if queue
 */
typedef struct queue_s
{
	int n;
	struct queue_s *prev;
	struct queue_s *next;
	int is_stack;
} _queue_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(__stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @file: file descriptor
 * @line: line read from file
 * @line_number: line number
 * @stack: stack
 *
 * Description: global variables
 */
typedef struct global_s
{
	FILE *file;
	char **line;
	int line_number;
	__stack_t *stack;
} global_t;

global_t globe;

/* auxiliary functions */
void (*get_op_func(char *s))(__stack_t **stack, unsigned int line_number);
void free_stack(__stack_t *head);
void free_all(__stack_t *head, FILE *fd);
int is_number(char *str);
char **split(char *str, char *delim);

/* opcode functions */
void f_push(__stack_t **stack, unsigned int line_number);
void f_pall(__stack_t **stack, unsigned int line_number);
void f_pint(__stack_t **stack, unsigned int line_number);
void f_pop(__stack_t **stack, unsigned int line_number);
void f_swap(__stack_t **stack, unsigned int line_number);
void f_add(__stack_t **stack, unsigned int line_number);
void f_nop(__stack_t **stack, unsigned int line_number);
void f_sub(__stack_t **stack, unsigned int line_number);
void f_div(__stack_t **stack, unsigned int line_number);
void f_mul(__stack_t **stack, unsigned int line_number);
void f_mod(__stack_t **stack, unsigned int line_number);
void f_pchar(__stack_t **stack, unsigned int line_number);
void f_pstr(__stack_t **stack, unsigned int line_number);
void f_rotl(__stack_t **stack, unsigned int line_number);
void f_rotr(__stack_t **stack, unsigned int line_number);
void f_stack(__stack_t **stack, unsigned int line_number);
void f_queue(__stack_t **stack, unsigned int line_number);

#endif /* MAIN_H */
