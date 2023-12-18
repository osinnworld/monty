#include "monty.h"

/**
 * nop - Does nothing
 * @stack: parameter
 * @l_num: parameter
 */
void nop(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	(void)stack;
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: parameter
 * @l_num: parameter
 */
void pchar(stack_t **stack, unsigned int l_num)
{
	int vl;
	
	if (stack == NULL || *stack == NULL)
	{
		string_error(11, l_num);
	}

	vl = (*stack)->n;
	if (vl < 0 || vl > 127)
	{
		string_error(10, l_num);
	}

	printf("%c\n", vl);
}
