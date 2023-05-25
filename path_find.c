#include "shell.h"

/**
 * r_path_execute_func - function that executes the command
 * 
 * @command: is the full path to the command
 * @vars: is the pointer to struct of variables
 * 
 * Return: 0 succcess or 1 failure
 * 
 */
int r_path_execute_func(char *command, vars_t *vars)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			r_print_error_func(vars, NULL);
		if (child_pid == 0)
		{
			if (execve(command, vars->av, vars->env) == -1)
				r_print_error_func(vars, NULL);
		}
		else
		{
			wait(&vars->status);
			if (WIFEXITED(vars->status))
				vars->status = WEXITSTATUS(vars->status);
			else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
				vars->status = 130;
			return (0);
		}
		vars->status = 127;
		return (1);
	}
	else
	{
		r_print_error_func(vars, ": Permission denied\n");
		vars->status = 126;
	}
	return (0);
}

/**
 * r_find_path_func - function that finds PATH
 * 
 * @env: is an array of environment variables
 * 
 * Return: node that contains the PATH or NULL on failure
 * 
 */
char *r_find_path_func(char **env)
{
	char *path = "PATH=";
	unsigned int i;
	unsigned int j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);

}

/**
 * r_check_for_path_func - function that checks if the command is in the PATH
 * 
 * @vars: is variables
 * 
 * Return: 0
 * 
 */
void r_check_for_path_func(vars_t *vars)
{
	char *path;
	char *path_dup = NULL, *check = NULL;
	unsigned int i = 0;
	unsigned int r = 0;
	char **path_tokens;
	struct stat buf;

	if (r_check_for_dir_func(vars->av[0]))
		r = r_execute_cwd_func(vars);
	else
	{
		path = r_find_path_func(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup_func(path + 5);
			path_tokens = r_tokenize_func(path_dup, ":");
			for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
			{
				check = _strcat_func(path_tokens[i], vars->av[0]);
				if (stat(check, &buf) == 0)
				{
					r = r_path_execute_func(check, vars);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
				vars->status = 127;
				r_new_exit_func(vars);
			}
		}
		if (path == NULL || path_tokens[i] == NULL)
		{
			r_print_error_func(vars, ": not found\n");
			vars->status = 127;
		}
		free(path_tokens);
	}
	if (r == 1)
		r_new_exit_func(vars);
}

/**
 * r_execute_cwd_func - function executes the command
 * 
 * @vars: is a pointer to struct of variables
 * 
 * Return: 0 success or 1 failure
 * 
 */
int r_execute_cwd_func(vars_t *vars)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(vars->av[0], &buf) == 0)
	{
		if (access(vars->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				r_print_error_func(vars, NULL);
			if (child_pid == 0)
			{
				if (execve(vars->av[0], vars->av, vars->env) == -1)
					r_print_error_func(vars, NULL);
			}
			else
			{
				wait(&vars->status);
				if (WIFEXITED(vars->status))
					vars->status = WEXITSTATUS(vars->status);
				else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
					vars->status = 130;
				return (0);
			}
			vars->status = 127;
			return (1);
		}
		else
		{
			r_print_error_func(vars, ": Permission denied\n");
			vars->status = 126;
		}
			return (0);
	}
	r_print_error_func(vars, ": not found\n");
	vars->status = 127;
	return (0);
}

/**
 * r_check_for_dir_func - function that checks the command is a part of a path
 * 
 * @str: is a command
 *
 * Return: 1 success or 0 failure
 * 
 */
int r_check_for_dir_func(char *str)
{
	unsigned int k;

	for (k = 0; str[k]; k++)
	{
		if (str[k] == '/')
			return (1);
	}
	return (0);
}
