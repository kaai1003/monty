#include "monty.h"

void addToStack(stack_t **newNode, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;
    if (newNode == NULL || *newNode == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *newNode;
        return;
    }
    tmp = head;
    head = *newNode;
    head->next = tmp;
    tmp-> prev = head;
}

void printStack (stack_t **stack, unsigned int line_num)
{
    stack_t *tmp;
    (void) line_num;
    if (stack == NULL)
    exit(EXIT_FAILURE);
    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    
}

void popTop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

void printTop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}