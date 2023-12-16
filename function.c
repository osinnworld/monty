#include "monty.h"

/**
 * find_func - Finds the appropriate function for the given opcode.
 * @opcode: parameter
 * @arg: parameter
 * @fmt: parameter
 * @l_num: parameter
 * Return: void
 */
void find_func(char *opcode, char *arg, int l_num, int fmt)
{
	int x, f;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", show_stack},
		{"pint", show_top},
		{"pop", pop_top},
		{"no_opera", no_opera},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mult_nodes},
		{"mod", modul_nodes},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotate_left},
		{"rotate_right", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			call_function(func_list[x].f, opcode, arg, l_num, fmt);
			f = 0;
		}
	}

	if (f == 1)
		err(3, l_num, opcode);
}

/**
 * call_function - Invokes the necessary function.
 * @func: parameter
 * @oper: parameter
 * @opcode: parameter
 * @vl: parameter
 * @l_num: parameter
 * @fmt: parameter
 */
void call_function(func_op func, char *oper, char *vl, int l_num, int fmt)
{
	stack_t *node;
	int f;
	int x;

	f = 1;

	if (strcmp(oper, "push") == 0)
	{
		if (vl != NULL && vl[0] == '-')
		{
			vl = vl + 1;
			f = -1;
		}

		if (vl == NULL)
			err(5, l_num);
		for (x = 0; vl[x] != '\0'; x++)
		{
			if (isdigit(vl[x]) == 0)
				err(5, l_num);
		}

		node = create_node(atoi(vl) * f);
		if (fmt == 0)
			func(&node, l_num);
		if (fmt == 1)
			add_queue(&node, l_num);
	}
	else
		func(&head, l_num);
}
