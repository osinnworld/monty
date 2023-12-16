#include "monty.h"

/**
 * err - outputs relevant error messages based on the provided error code
 * @error_code: parameter
 */
void err(int error_code, ...)
{
	va_list args;
	char *opr;
	int l_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error:Can't open file %s\n",
					va_arg(args, char *));
			break;
		case 3:
			l_num = va_arg(args, int);
			opr = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - manages errors related to string operations
 * @error_code: parameter
 */
void string_error(int error_code, ...)
{
	va_list args;
	int l_num;

	va_start(args, error_code);
	l_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, vl out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - manages errors with corresponding error codes
 * @error_code: parameter
 */
void more_error(int error_code, ...)
{
	va_list args;
	char *opr;
	int l_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(args, int));
			break;
		case 8:
			l_num = va_arg(args, unsigned int);
			opr = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
