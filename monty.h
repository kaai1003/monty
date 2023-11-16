#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*errors_fun.c*/
void err(int code_err, ...);
void string_err(int code_err, ...);
void more_err(int code_err, ...);
int parse_line(char *buffer, int line_number, int format);
/*main.c*/
int main(int argc, char *argv[]);
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
/*stack.c*/
void multiNodes(stack_t **stack, unsigned int line_num);
void modNodes(stack_t **stack, unsigned int line_num);
/*stackFun1.c*/
void addToStack(stack_t **newNode, __attribute__((unused)) unsigned int ln);
void printStack (stack_t **stack, unsigned int line_num);
void popTop(stack_t **stack, unsigned int line_number);
void printTop(stack_t **stack, unsigned int line_number);
/*stackFun2.c*/
void Nop(stack_t **stack, unsigned int line_num);
void swapNodes(stack_t **stack, unsigned int line_num);
void addNodes(stack_t **stack, unsigned int line_num);
void subNodes(stack_t **stack, unsigned int line_num);
void divNodes(stack_t **stack, unsigned int line_num);
/*strings.c*/
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);
/*tools.c*/
void open_file (char *file);
void read_file(FILE *jv);
/*other func*/
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
void call_fun(op_func, char *, char *, int, int);

#endif