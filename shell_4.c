#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * r_sig_handler_func - Function that handles C signal
 *
 * @uuv: The unused variable
 */
static void r_sig_handler_func(int uuv)
{
	(void)uuv;
	_puts_func("\n$ ");
}

/**
 * main - Main function for the shell project
 *
 * @argc: The number of arguments passed to main
 * @argv: An array of arguments passed to main
 * @environment: An array of environment variables
 *
 * Return: 0 or exit status
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int is_pipe = 0;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};
	unsigned int i;

	vars.argv = argv;
	vars.env = r_make_env_func(environment);
	signal(SIGINT, r_sig_handler_func);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts_func("$ ");
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.count++;
		vars.commands = r_tokenize_func(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.av = r_tokenize_func(vars.commands[i], "\n \t\r");
			if (vars.av && vars.av[0])
			{
				if (check_for_builtins(&vars) == NULL)
					r_check_for_path_func(&vars);
			}
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		if (is_pipe == 0)
			_puts_func("$ ");
		vars.buffer = NULL;
	}
	if (is_pipe == 0)
		_puts_func("\n");
	r_free_env_func(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
