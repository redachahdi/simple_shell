#include "shell.h"


/**
 * get_env_func - function that gets the value variable
 *
 * @name: is the name of the global variable
 * Return: is the string of value
 */
char *get_env_func(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
 * add_node_end_func - function that adds a new nod
 *
 * @head: is the pointer
 * @str: is the pointer
 *
 * Return: is the address of the new element
 */

list_path *add_node_end_func(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * linkpath - function that creates the linked list
 *
 * @path: is the string of path value
 * Return: is the pointer
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = strdup_func(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end_func(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * fil_which_func - function that finds the pathname
 *
 * @filename: is the name of file or command
 * @head: head of linked list of path directorie
 *
 * Return: pathname of filename or NULL if no match
 */
char *fil_which_func(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = all_func(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * list_free_func - frees a list_t
 *@head: pointer to our linked list
 */
void list_free_func(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
