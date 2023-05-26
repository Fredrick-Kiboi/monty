#include "monty.h"

void malloc_failure(char failed)
{
    if (failed)
    {
        write(STDERR_FILENO, "Error: malloc failed\n", 21);
        exit_program(EXIT_FAILURE);
    }
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr = NULL;
    unsigned int min_size = old_size < new_size ? old_size : new_size;
    unsigned int i;

    if (new_size == old_size)
        return ptr;

    if (ptr != NULL)
    {
        if (new_size == 0)
        {
            free(ptr);
            return NULL;
        }
        new_ptr = malloc(new_size);
        if (new_ptr != NULL)
        {
            for (i = 0; i < min_size; i++)
                *((char *)new_ptr + i) = *((char *)ptr + i);
            free(ptr);
            return new_ptr;
        }
        free(ptr);
        malloc_failure(new_ptr == NULL);
        return NULL;
    }
    else
    {
        new_ptr = malloc(new_size);
        malloc_failure(new_ptr == NULL);
        return new_ptr;
    }
}

void mem_set(char *str, int n, char c)
{
    int i;

    for (i = 0; (str != NULL) && (i < n); i++)
        *(str + i) = c;
}

