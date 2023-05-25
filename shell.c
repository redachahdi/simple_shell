#include "shell.h"

/* global variable for ^C handling */
unsigned int sign_flags;

/**
 * r_sig_handler_func - function that handles ^C signal
 * 
 * @uuv: is the unused variable
 * 
 * Return: 0
 * 
 */
static void r_sig_handler_func(int uuv)
{
	(void) uuv;
	if (sign_flags == 0)
		_puts_func("\n$ ");
	else
		_puts_func("\n");
}

/**
 * main - the main function for the shell
 * 
 * @argc: is the number of arguments passed to main
 * @argv: is an array of arguments passed to main
 * @environment: is an array of environment variables
 * 
 * Return: 0 or exit status
 * 
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int is_pipe = 0, i;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;
	vars.env = r_make_env_func(environment);
	signal(SIGINT, r_sig_handler_func);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts_func("$ ");
	sign_flags = 0;
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		sign_flags = 1;
		vars.count++;
		vars.commands = r_tokenize_func(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.av = r_tokenize_func(vars.commands[i], "\n \t\r");
			if (vars.av && vars.av[0])
				if (check_for_builtins(&vars) == NULL)
					r_check_for_path_func(&vars);
		free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		sign_flags = 0;
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
