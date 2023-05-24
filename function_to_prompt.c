#include "main.h"

/**
 * prompt_func - function to display
 */
void prompt_func(void)
{
	PRINTER("$: ");
}
/**
 * eror_print - function to display error
 * 
 * @input:is the user input
 * @nombre:is the simple shell count 
 * @argv:is the program, name
 *
 * Return: Void
 */
void eror_print(char *input, int nombre, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = itoa_func(nombre);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
