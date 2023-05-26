#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * r_make_env_func - is the function that makes shell environment
 *
 * @env: is the environment passed to main
 *
 * Return: is the new environment
 *
 */
char **r_make_env_func(char **env)
{
	char **newenv = NULL;
	size_t k;

	for (k = 0; env[k] != NULL; k++)
		;
	newenv = malloc(sizeof(char *) * (k + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (k = 0; env[k] != NULL; k++)
		newenv[k] = _strdup_func(env[k]);
	newenv[k] = NULL;
	return (newenv);
}

/**
 * r_free_env_func - is the function that the frees shell environment
 *
 * @env: is the shell environment
 *
 * Return: 0
 *
 */
void r_free_env_func(char **env)
{
	unsigned int k;

	for (k = 0; env[k] != NULL; k++)
		free(env[k]);
	free(env);
}
