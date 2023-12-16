#include "monty.h"

/**
 * add_stack - pushes a new node inti the new stack
 * @n_node: parameter
 * @l_num: parameter
 */
void add_stack(stack_t **n_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *n_node;
		return;
	}

	tmp = head;
	head = *n_node;
	head->nxt = tmp;
	tmp->prev = head;
}
/**
 * show_stack - Displays the contents of the stack
 * @stack: parameter
 * @l_num: parameter
 */
void show_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->nxt;
	}
}

/**
 * pop_top - removes the top node from the stack
 * @stack: parameter
 * @l_num: parameter
 */
void pop_top(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_error(7, l_num);

	tmp = *stack;
	*stack = tmp->nxt;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * show_top - Displays the top node of the stack
 * @stack: parameter
 * @l_num: parameter
 */
void show_top(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, l_num);

	printf("%d\n", (*stack)->n);
}
