#include "monty.h"

/**
 * handle_malloc_failure - Performs the necessary actions for a malloc failure
 * @failed: Specifies if malloc failed
 */
void handle_malloc_failure(char failed)
{
    if (failed)
    {
        write(STDERR_FILENO, "Error: malloc failed\n", 21);
        exit_program(EXIT_FAILURE);
    }
}

/**
 * my_realloc - Reallocates a memory block
 * @ptr: The pointer to the previous memory block
 * @old_size: The size of the old memory block
 * @new_size: The size of the new memory block
 *
 * Return: The pointer to the new memory block, otherwise NULL
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
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
        handle_malloc_failure(new_ptr == NULL);
        return NULL;
    }
    else
    {
        new_ptr = malloc(new_size);
        handle_malloc_failure(new_ptr == NULL);
        return new_ptr;
    }
}

/**
 * set_memory - Fills a section of a buffer with a given byte
 * @buffer: The buffer containing the section to be filled
 * @length: The length of the buffer to fill
 * @byte: The byte to fill the buffer's section with
 */
void set_memory(char *buffer, int length, char byte)
{
    int i;

    for (i = 0; (buffer != NULL) && (i < length); i++)
        *(buffer + i) = byte;
}
