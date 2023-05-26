#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * check_for_builtins - is the function that checks the command
 *
 * @vars: is a variables
 *
 * Return: the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtins_t check[] = {
		{"exit", r_new_exit_func},
		{"env", _env_func},
		{"setenv", r_new_setenv_func},
		{"unsetenv", r_new_unsetenv_func},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmpr_func(vars->av[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

/**
 * r_new_exit_func - is the function that exit from program
 *
 * @vars: is the variables
 *
 * Return: is the 0
 */
void r_new_exit_func(vars_t *vars)
{
	int status;

	if (_strcmpr_func(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = _atoi_func(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			r_print_error_func(vars, ": Illegal number: ");
			_puts2_func(vars->av[1]);
			_puts2_func("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	r_free_env_func(vars->env);
	exit(vars->status);
}

/**
 * _env_func - is the function that prints the environment
 *
 * @vars: is the struct of variables
 *
 * Return: is the 0
 *
 */
void _env_func(vars_t *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts_func(vars->env[i]);
		_puts_func("\n");
	}
	vars->status = 0;
}

/**
 * r_new_setenv_func - is the function create a new environment variable
 *
 * @vars: is a pointer to struct of variables
 *
 * Return: is the 0
 *
 */
void r_new_setenv_func(vars_t *vars)
{
	char **key;
	char *var;

	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		r_print_error_func(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = r_find_key_func(vars->env, vars->av[1]);
	if (key == NULL)
		r_add_key_func(vars);
	else
	{
		var = r_add_value_func(vars->av[1], vars->av[2]);
		if (var == NULL)
		{
			r_print_error_func(vars, NULL);
			free(vars->buffer);
			free(vars->commands);
			free(vars->av);
			r_free_env_func(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}

/**
 * r_new_unsetenv_func - is the function that remove an environment variable
 *
 * @vars: pointer to a struct of variables
 *
 * Return: 0
 *
 */
void r_new_unsetenv_func(vars_t *vars)
{
	char **key;
	char **newenv;

	unsigned int i, j;

	if (vars->av[1] == NULL)
	{
		r_print_error_func(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = r_find_key_func(vars->env, vars->av[1]);
	if (key == NULL)
	{
		r_print_error_func(vars, ": No variable to unset");
		return;
	}
	for (i = 0; vars->env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		r_print_error_func(vars, NULL);
		vars->status = 127;
		r_new_exit_func(vars);
	}
	for (i = 0; vars->env[i] != *key; i++)
		newenv[i] = vars->env[i];
	for (j = i + 1; vars->env[j] != NULL; j++, i++)
		newenv[i] = vars->env[j];
	newenv[i] = NULL;
	free(*key);
	free(vars->env);
	vars->env = newenv;
	vars->status = 0;
}
