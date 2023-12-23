#include "main.h"

/**
 * _print - it writes array of chars
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or
 * On error, -1 is returned, and errno is set
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}


/**
 * _printerr - writes array of chars in the standar error
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or
 * On error, -1 is returned, and errno
 */

int _printerr(char *string)
{
	return (write(STDERR_FILENO, string, _strlen(string)));
}
