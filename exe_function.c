#include "main.h"


/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **to_split_str_func(char *str, const char *delim)
{
	int a;
	int bb;
	char **array;
	char *token;
	char *copy;

	copy = malloc(strlen_func(str) + 1);
	if (copy == NULL)
	{
		perror(get_env_func("_"));
		return (NULL);
	}
	a = 0;
	while (str[a])
	{
		copy[a] = str[a];
		a++;
	}
	copy[a] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = strdup_func(token);

	a = 1;
	bb = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = realloc_func(array, (sizeof(char *) * (bb - 1)), (sizeof(char *) * bb));
		array[a] = strdup_func(token);
		a++;
		bb++;
	}
	free(copy);
	return (array);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int e;
	int status;

	if (!argv || !argv[0])
		return;
	e = fork();
	if (e == -1)
	{
		perror(get_env_func("_"));
	}
	if (e == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *realloc_func(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int a;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (a = 0; a < old_size; a++)
			new[a] = old[a];
		free(ptr);
		for (a = old_size; a < new_size; a++)
			new[a] = '\0';
	}
	if (new_size < old_size)
	{
		for (a = 0; a < new_size; a++)
			new[a] = old[a];
		free(ptr);
	}
	return (new);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */

void fre_arv_func(char **arv)
{
	int a;

	for (a = 0; arv[a]; a++)
		free(arv[a]);
	free(arv);
}
