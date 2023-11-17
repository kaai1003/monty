#include "monty.h"
/**
 * multiNodes - multiply 2 elements of the top stack
 * @stack: pointer to stack
 * @line_num: line number
 *
 * Return: nothing
 */
void multiNodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * modNodes - find modulo of 2 top elemnts of stack
 * @stack: pointer to stack
 * @line_num: line number
 *
 * Return: nothing
 */
void modNodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
