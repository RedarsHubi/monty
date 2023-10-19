#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

void exec(char *codelines[], stack_t *stack);
void free_s(stack_t *head);
void free_l(char *a[]);
void add_t_two(stack_t **stack, unsigned int line_number);
void p_top(stack_t **stack, unsigned int line_number);
void push_t(stack_t **stack, unsigned int line_number, int value);
void pop_st(stack_t **stack, unsigned int line_number);
void swp_t_two(stack_t **stack, unsigned int line_number);
void p_all(stack_t **stack, unsigned int line_num);
int pshint(char *list, int ln);
int combfind(char *list, int ln);

#endif
