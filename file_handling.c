#include "monty.h"

/**
 * open_file - Opens a file for reading.
 * @f_name: parameter
 * Return: parameter
 */
void open_file(char *f_name)
{
	FILE *f_dest = fopen(f_name, "r");

	if (f_name == NULL || f_dest == NULL)
		err(2, f_name);

	read_file(f_dest);
	fclose(f_dest);
}

/**
 * read_file - Reads the contents of a file.
 * @f_dest: parameter
 * Return: parameter
 */
void read_file(FILE *f_dest)
{
	int l_num, fmt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buffer, &len, f_dest) != -1; l_num++)
	{
		fmt = parse_line(buffer, l_num, fmt);
	}
	free(buffer);
}
