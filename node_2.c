#include "monty.h"
/**
 * no_opera - performs no operation
 * @stack: parameter
 * @l_num: parameter
 */
void no_opera(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}
/**
 * swap_nodes - Exchanges the positions of the top two elements
 * @stack: parameter
 * @l_num: parameter
 */
void swap_nodes(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_error(8, l_num, "swap");

	tmp = (*stack)->nxt;
	(*stack)->nxt = tmp->nxt;

	if (tmp->nxt != NULL)
		tmp->nxt->prev = *stack;

	tmp->nxt = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add_nodes - computes the sum of the top two elements
 * @stack: parameter
 * @l_num: parameter
 */
void add_nodes(stack_t **stack, unsigned int l_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_error(8, l_num, "and");

	(*stack) = (*stack)->nxt;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)-> result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_nodes - Subtracts the top element from the bottom element
 * @stack: parameter
 * @l_num: parameter
 */
void sub_nodes(stack_t **stack, unsigned int l_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->NULL)
		more_error(8, l_num, "sub");

	(*stack) = (*stack)->nxt;
	result = (*stack)->n - (*stack)->prev->n;

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Divides the second element from the top
 * @stack: parameter
 * @l_num: parameter
 */
void div_nodes(stack_t **stack, unsigned int l_num)
{
	int r;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_error(8, l_num, "div");

	if ((*stack)->n == 0)
		more_error(9, l_num);

	(*stack)->n = r;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
