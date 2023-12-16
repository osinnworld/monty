#include "monty.h"

/**
 * create_node - Allocates memory for a node and assigns a value
 * @vl: parameter
 * Return: upon success
 */
stack_t *create_node(int n)
{
	stack_t *nod = malloc(sizeof(stack_t));

	if (nod == NULL)
		err(4);

	nod->nxt = NULL;
	nod->prev = NULL;
	nod->n = n;
	return (nod);
}
/**
 * free_nodes - Releases memory allocated for nodes in the stack
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->nxt;
		free(tmp);
	}
}

/**
 * add_queue - Adds a node to the stack or queue
 * @n_node: parameter
 * @l_num: parameter
 */
void add_queue(stack_t **n_node, __attribute__((unused))unsigned int l_num)
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
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;

	tmp->nxt = *n_node;
	(*n_node)->prev = tmp;
}
