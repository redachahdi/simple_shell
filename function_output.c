#include "main.h"
/**
 *  p_rerror - function to print error
 *
 * @argv:is the program name
 * @c: is the error Count
 * @cmd:is thhe command
 *
 * Return: is the Void
 */
void p_rerror(char **argv, int c, char **cmd)
{
	char *er = itoa_func(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
