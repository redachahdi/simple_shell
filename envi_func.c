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
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup_func(env[i]);
	newenv[i] = NULL;
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
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
