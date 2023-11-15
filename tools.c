#include "monty.h"
/**
 * open_file - open monty file
 * @file: file name
 *
 * Return: read file
 */
FILE *open_file(char *file)
{
	FILE *o;

	o = fopen(file, "r");
	if (o == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	return (o);
}
/**
 * split_line - tokenize line file
 * @buff: pointer to line
 * @file: file name
 * @nline: line number
 *
 * Return: nothing to return
 */
void split_line(char *buff, char *file, int nline)
{
	char *opcodes[2] = {NULL, NULL};

	opcodes[0] = strtok(buff, "\t \n");
	
