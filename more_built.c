#include "shell.h"

/**
 * r_add_key_func - function that create environment variable
 * 
 * @vars: is a pointer to struct of variables
 * 
 * Return: 0
 * 
 */
void r_add_key_func(vars_t *vars)
{
	unsigned int i;
	char **newenv;

	for (i = 0; vars->env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 2));
	if (newenv == NULL)
	{
		r_print_error_func(vars, NULL);
		vars->status = 127;
		r_new_exit_func(vars);
	}
	for (i = 0; vars->env[i] != NULL; i++)
		newenv[i] = vars->env[i];
	newenv[i] = r_add_value_func(vars->av[1], vars->av[2]);
	if (newenv[i] == NULL)
	{
		r_print_error_func(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->av);
		r_free_env_func(vars->env);
		free(newenv);
		exit(127);
	}
	newenv[i + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}

/**
 * r_find_key_func - function that finds an environment variable
 * 
 * @env: is an array of environment variables
 * @key: is an environment variable to find
 *
 * Return: address
 * 
 */
char **r_find_key_func(char **env, char *key)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	len = _strlen_func(key);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
			if (key[j] != env[i][j])
				break;
		if (j == len && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}

/**
 * r_add_value_func - function that create environment variable string
 * 
 * @key: is a variable name
 * @value: is a variable value
 *
 * Return: new string
 * 
 */
char *r_add_value_func(char *key, char *value)
{
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;
	char *new;

	len1 = _strlen_func(key);
	len2 = _strlen_func(value);
	new = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new == NULL)
		return (NULL);
	for (i = 0; key[i] != '\0'; i++)
		new[i] = key[i];
	new[i] = '=';
	for (j = 0; value[j] != '\0'; j++)
		new[i + 1 + j] = value[j];
	new[i + 1 + j] = '\0';
	return (new);
}

/**
 * _atoi_func - function that converts string into integer
 * 
 * @str: is a string to convert
 *
 * Return: integer value or -1
 * 
 */
int _atoi_func(char *str)
{
	unsigned int k;
	unsigned int digits;
	int _num = 0;
	int num_test;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (k = 0; str[k] != '\0' && k < digits; k++)
	{
		_num *= 10;
		if (str[k] < '0' || str[k] > '9')
			return (-1);
		if ((k == digits - 1) && (str[k] - '0' > INT_MAX % 10))
			return (-1);
		_num += str[k] - '0';
		if ((k == digits - 2) && (str[k + 1] != '\0') && (_num > INT_MAX / 10))
			return (-1);
	}
	if (k > digits)
		return (-1);
	return (_num);
}
