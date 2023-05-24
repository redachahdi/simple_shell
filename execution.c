#include "shell.h"


/**
 * to_split_str_func - function that splits the string
 *
 * @str: is the string
 * @delim: is the delimiter
 *
 * Return: array of pointers to words
 */

char **to_split_str_func(char *str, const char *delim)
{
	int i;
	int w;
	char **array;
	char *token;
	char *copy;

	copy = malloc(strlen_func(str) + 1);
	if (copy == NULL)
	{
		perror(get_env_func("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = strdup_func(token);

	i = 1;
	w = 3;
	while (token)
	{
		token = strtok(NULL, delim);
array = realloc_func(array, (sizeof(char *) * (w - 1)), (sizeof(char *) * w));
		array[i] = strdup_func(token);
		i++;
		w++;
	}
	free(copy);
	return (array);
}

/**
 * execute - function that executes the  command
 *
 * @argv: is the array
 * Return: is void
 */

void execute(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(get_env_func("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * realloc_func - function to reallocates memory
 *
 * @ptr: is the previous pointer
 * @old_size: is the old size of  the pointer
 * @new_size: is the new size for the pointer
 *
 * Return: is the new Pointer
 */

void *realloc_func(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

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
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * fre_arv_func - function that frees the array
 *
 * @arv: is the array of the pointers
 * Return: is void
 */

void fre_arv_func(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}

