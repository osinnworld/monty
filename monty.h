#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: parameter
 * @prev: parameter
 * @nxt: parameter
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *nxt;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: parameter
 * @f: parameter
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*func_op)(stack_t **, unsigned int);

void print_char(stack_t **stack, unsigned int l_num);
void print_string(stack_t **stack, __attribute__((unused))unsigned int l_num);
void rotate_left(stack_t **stack, unsigned int l_num);
void rotate_right(stack_t **stack, unsigned int l_num);
int parse_line(char *buffer, int l_num, int fmt);

void open_file(char *f_name);
void read_file(FILE *f_dest);

void find_func(char *opcode, char *arg, int l_num, int fmt);
void call_function(func_op func, char *oper, char *vl, int l_num, int fmt);

stack_t *create_node(int n);
void free_nodes(void);
void add_queue(stack_t **n_node, __attribute__((unused))unsigned int l_num);

void no_opera(stack_t **stack, unsigned int l_num);
void swap_nodes(stack_t **stack, unsigned int l_num);
void add_nodes(stack_t **stack, unsigned int l_num);
void sub_nodes(stack_t **stack, unsigned int l_num);
void div_nodes(stack_t **stack, unsigned int l_num);

void mult_nodes(stack_t **stack, unsigned int l_num);
void modul_nodes(stack_t **stack, unsigned int l_num);

void add_stack(stack_t **n_node, __attribute__((unused))unsigned int l_num);
void show_stack(stack_t **stack, unsigned int l_num);
void pop_top(stack_t **stack, unsigned int l_num);
void show_top(stack_t **stack, unsigned int l_num);

void err(int error_code, ...);
void string_error(int error_code, ...);
void more_error(int error_code, ...);

void pchar(stack_t **stack, unsigned int l_num);
void nop(stack_t **stack, unsigned int l_num);

#endif
