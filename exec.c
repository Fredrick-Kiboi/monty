#include "monty.h"

/**
 * get_opcode_handlers - Retrieves an array of supported instructions
 *
 * Return: An array of instructions supported by this program
 */
instruction_t *get_opcode_handlers(void)
{
    static instruction_t handlers[] = {
        {"push", mty_op_push},
        {"pall", mty_op_pall},
        {"pint", mty_op_pint},
        {"pop", mty_op_pop},
        {"swap", mty_op_swap},
        {"add", mty_op_add},
        {"nop", mty_op_nop},
        {"sub", mty_op_sub},
        {"div", mty_op_div},
        {"mul", mty_op_mul},
        {"mod", mty_op_mod},
        {"pchar", mty_op_pchar},
        {"pstr", mty_op_pstr},
        {"rotl", mty_op_rotl},
        {"rotr", mty_op_rotr},
        {"stack", mty_op_stack},
        {"queue", mty_op_queue},
        {NULL, NULL},
    };
    return handlers;
}

/**
 * execute_line - Executes a line of code
 * @line: The line to execute
 * @line_num: The line number of the line being executed
 * @stack: The stack of values of the program
 */
void execute_line(char *line, int line_num, stack_t **stack)
{
    instruction_t *opcodes = get_opcode_handlers();
    int i = 0, j;
    char *op = read_word(line, &i);

    if (op != NULL)
    {
        if ((op[0] != '#') && (op[0] != '\0'))
        {
            for (j = 0; opcodes[j].opcode != NULL; j++)
            {
                if (strcmp(op, opcodes[j].opcode) == 0)
                {
                    free(op);
                    opcodes[j].f(stack, line_num);
                    return;
                }
            }
            fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
            free(op);
            exit_program(EXIT_FAILURE);
        }
        free(op);
    }
}
