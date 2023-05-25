#include "shell.h"

/**
 * r_make_env_func - function that makes shell environment
 * 
 * @env: is the environment passed to main
 * 
 * Return: new environment
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
 * r_free_env_func - function that frees shell's environment
 * 
 * @env: is the shell's environment
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
