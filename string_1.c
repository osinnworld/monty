#include "monty.h"

/**
 * print_char - Displays the ASCII value.
 * @stack: parameter
 * @l_num: parameter
 */
void print_char(stack_t **stack, unsigned int l_num)
{
	int vl;

	if (stack == NULL || *stack == NULL)
		string_error(11, l_num);

	vl = (*stack)->n;
	if (vl < 0 || vl > 127)
		string_error(10, l_num);

	printf("%c\n", vl);
}

/**
 * print_string - Displays a string.
 * @stack: parameter
 * @l_num: parameter
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	int vl;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		vl = tmp->n;
		if (vl <= 0 || vl > 127)
			break;
		printf("%c", vl);
		tmp = tmp->nxt;
	}
	printf("\n");
}


/**
 * rotate_left - Moves the top node of the stack to the bottom.
 * @stack: parameter
 * @l_num: parameter
 */
void rotate_left(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		return;

	tmp = *stack;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;

	tmp->nxt = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->nxt;
	(*stack)->prev->nxt = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotate_right - Moves the last node of the stack to the top.
 * @stack: parameter
 * @l_num: parameter
 */
void rotate_right(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		return;

	tmp = *stack;

	while (tmp->nxt != NULL)
		tmp = tmp->nxt;

	tmp->nxt = *stack;
	tmp->prev->nxt = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

/**
 * parse_line - Breaks down each line into tokens
 * @buffer: parameter
 * @l_number: parameter
 * @fmt: parameter
 * Return: Returns 0 if the opcode is for stack, 1 if for queue.
 */
int parse_line(char *buffer, int l_num, int fmt)
{
	char *opcode, *f;
	const char *delimi = "\n ";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delimi);

	if (opcode == NULL)
		return (fmt);
	f = strtok(NULL, delimi);
	
	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, f, l_num, fmt);
	return (fmt);
}
