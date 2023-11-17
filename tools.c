#include "monty.h"
/**
 * open_file - open monty file
 * @file: file name
 *
 * Return: nothing
 */
void open_file(char *file)
{
	FILE *jv = fopen(file, "r");

	if (file == NULL || jv == NULL)
		err(3, file);
	read_file(jv);
	fclose(jv);
}
/**
 * read_file - read monty file
 * @jv: file descriptor
 *
 * Return: nothing
 */
void read_file(FILE *jv)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, jv) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}
/**
 * parse_line - split line for opcode
 * @buffer: pointer to line
 * @line_number: number of line
 * @format: output
 *
 * Return: format output
 */
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n \t";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL || opcode[0] == '#')
		return (format);
	val = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, val, line_number, format);
	return (format);
}
/**
 * find_func - check opcode funcs
 * @opcode: pointer to opcode
 * @value: opcode arg
 * @ln: line number
 * @format: output
 *
 * Return: nothing
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", addToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", Nop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", multiNodes},
		{"mod", modNodes},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}
/**
 * call_fun - execute opcode func
 * @func: opcode func
 * @op: pointer to opcode
 * @val: opcode arg
 * @ln: line number
 * @format: output
 *
 * Return: nothing
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int i;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
