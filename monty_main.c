#include "monty.h"

static stack_t *Values;
static char **Lines;
static int Lines_Count;
static int Current_Line;
static char Data_Format;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        Data_Format = DF_LIFO;
        Lines = read_file(argv[1], &Lines_Count);
        while (Current_Line < Lines_Count)
        {
            execute_line(Lines[Current_Line], Current_Line + 1, &Values);
            Current_Line++;
        }
    }
    else
    {
        write(STDERR_FILENO, "USAGE: monty file\n", 18);
        exit(EXIT_FAILURE);
    }
    clean_up_program();
    return EXIT_SUCCESS;
}

char *get_data_mode(void)
{
    return &Data_Format;
}

char **get_lines(void)
{
    return Lines;
}

void clean_up_program(void)
{
    stack_t *node = Values, *tmp = NULL;
    int i;

    if (Lines != NULL)
    {
        for (i = 0; i < Lines_Count; i++)
        {
            if (Lines[i] != NULL)
                free(Lines[i]);
        }
        free(Lines);
    }

    if (node != NULL)
    {
        while (node->prev != NULL)
            node = node->prev;

        while (node != NULL)
        {
            tmp = node->next;
            free(node);
            node = tmp;
        }
    }
}

void exit_program(int status)
{
    clean_up_program();
    exit(status);
}

