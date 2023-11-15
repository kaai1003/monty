#include "monty.h"
/**
 * main - execute opcodes like monty language
 * @argc: number of arguments passed to main
 * @argv: arguments passed to main
 *
 * Return: return 0
 */
int main(argc, **argv)
{
	FILE *f;
	char *buff = NULL;
	int r = 0, count = 1;
	size_t size = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = open_file(argv[1]);
	r = getline(&buff, &size, f);
	while (r != -1)
	{
		split_line(buff, argv[1], count);
		count++;
	}
