#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 *
 * @c: the character to write
 *
 * Return: On success, returns 1.
 * On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

