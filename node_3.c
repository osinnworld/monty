#include "monty.h"

/**
 * mult_nodes - Multiplies the top two elements of the stack
 * @stack: parameter
 * @l_num: parameter
 */
void mult_nodes(stack_t **stack, unsigned int l_num)
{
	int r;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_error(8, l_num, "mul");

	(*stack) = (*stack)->nxt;
	r = (*stack)->n * (*stack)->prev->n;

	(*stack)->n = r;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modul_nodes - Computes the remainder of the top two elements in the stack
 * @stack: parameter
 * @l_num: parameter
 */
void modul_nodes(stack_t **stack, unsigned int l_num)
{
	int r;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_error(8, l_num, "mod");

	if ((*stack)->n == 0)
		more_error(9, l_num);

	(*stack) = (*stack)->nxt;
	r = (*stack)->n % (*stack)->prev->n;

	(*stack)->n = r;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
