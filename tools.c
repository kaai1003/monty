#include "monty.h"

void open_file (char *file)
{
    FILE *jv = fopen(file, "r");
    if (file == NULL || jv == NULL)
        err(3, file);
    read_file(jv);
    fclose(jv);
}

/*Betty doc*/

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
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_number, format);
	return (format);
}

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