#include "monty.h"

void err(int code_err, ...)
{
    va_list ag;
    char *rv;
    int num;

    va_start(ag, code_err);
    switch (code_err)
    {
    case 1:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 2:
        fprintf(stderr, "Error 404: Can't open file %s\n", va_arg(ag, char *));
        break;
    case 3:
        rv = va_arg(ag, char *);
        num = va_arg(ag, int);
        fprintf(stderr, "L%d: ybjbiwb ubstryctuib %s\n", num, rv);
        break;
    case 4:
    fprintf(stderr, "Error: malloc failed\n");
    break;
    case 5:
    fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
    break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

void string_err(int code_err, ...)
{
	va_list ag;
	int num;

	va_start(ag, code_err);
	num = va_arg(ag, int);
	switch (code_err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void more_err(int code_err, ...)
{
	va_list ag;
	char *op;
	int num;

	va_start(ag, code_err);
	switch (code_err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}