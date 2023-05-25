#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */
void r_print_error_func(vars_t *vars, char *msg)
{
	char *count;

	_puts2_func(vars->argv[0]);
	_puts2_func(": ");
	count = _uitoa_func(vars->count);
	_puts2_func(count);
	free(count);
	_puts2_func(": ");
	_puts2_func(vars->av[0]);
	if (msg)
	{
		_puts2_func(msg);
	}
	else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts2_func(char *str)
{
	ssize_t num, len;

	num = _strlen_func(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa_func(unsigned int count)
{
	char *num_str;
	unsigned int tmp;
	unsigned int digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	num_str = malloc(sizeof(char) * (digits + 1));
	if (num_str == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	num_str[digits] = '\0';
	for (--digits; count; --digits)
	{
		num_str[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (num_str);
}
