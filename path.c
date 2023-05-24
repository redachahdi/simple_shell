#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * exit_func - function that exits the shell
 *
 * @arv: array of words of the entered line
 * Return: void
 */
void exit_func(char **arv)
{
	int k, b;

	if (arv[1])
	{
		b = atoi_func(arv[1]);
		if (b <= -1)
			b = 2;
		freearv(arv);
		exit(b);
	}
	for (k = 0; arv[k]; k++)
		free(arv[k]);
	free(arv);
	exit(0);
}

/**
 * atoi_func - function that converts the string into an integer
 *
 * @s: the pointer to the string
 * Return: the converted integer
 */
int atoi_func(char *s)
{
	int k;
	int int_r = 0;
	int sign = 1;

	k = 0;
	while (!((s[k] >= '0') && (s[k] <= '9')) && (s[k] != '\0'))
	{
		if (s[k] == '-')
		{
			sign = sign * (-1);
		}
		k++;
	}
	while ((s[k] >= '0') && (s[k] <= '9'))
	{
		int_r = (int_r * 10) + (sign * (s[k] - '0'));
		k++;
	}
	return int_r;
}

/**
 * envir_func - function that prints the environment
 *
 * @arv: the array
 */
void envir_func(char **arv __attribute__ ((unused)))
{
	int k;

	for (k = 0; environ[k]; k++)
	{
		puts_func(environ[k]);
		puts_func("\n");
	}
}

/**
 * set_env_func - function that sets a new environment variable
 *
 * @arv: the array
 */
void set_env_func(char **arv)
{
	int a, b, c;

	if (!arv[1] || !arv[2])
	{
		perror(getenv_func("_"));
		return;
	}

	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (arv[1][b] == environ[a][b])
		{
			while (arv[1][b])
			{
				if (arv[1][b] != environ[a][b])
					break;

				b++;
			}
			if (arv[1][b] == '\0')
			{
				c = 0;
				while (arv[2][c])
				{
					environ[a][b + 1 + c] = arv[2][c];
					c++;
				}
				environ[a][b + 1 + c] = '\0';
				return;
			}
		}
	}
	if (!environ[a])
	{
		environ[a] = malloc(sizeof(char) * (strlen(arv[1]) + strlen(arv[2]) + 2));
		if (environ[a] == NULL)
			return;

		sprintf(environ[a], "%s=%s", arv[1], arv[2]);
		environ[a + 1] = NULL;
	}
}

/**
 * u_setenv_func - function that removes an environment variable
 *
 * @arv: the array
 */
void u_setenv_func(char **arv)
{
	int a, b;

	if (!arv[1])
	{
		perror(getenv_func("_"));
		return;
	}
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (arv[1][b] == environ[a][b])
		{
			while (arv[1][b])
			{
				if (arv[1][b] != environ[a][b])
					break;

				b++;
			}
			if (arv[1][b] == '\0')
			{
				free(environ[a]);
				environ[a] = environ[a + 1];
				while (environ[a])
				{
					environ[a] = environ[a + 1];
					a++;
				}
				return;
			}
		}
	}
}

/**
 * built_check_func - function that checks if the command is a built-in
 *
 * @arv: the array of arguments
 * Return: pointer to function that takes arv and returns void
 */
void (*built_check_func(char **arv))(char **arv)
{
	int i, j;
	struct ourbuild T[] = {
		{"exit", exit_func},
		{"env", envir_func},
		{"setenv", set_env_func},
		{"unsetenv", u_setenv_func},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			while (arv[0][j])
			{
				if (T[i].name[j] != arv[0][j])
					break;
				j++;
			}
			if (!arv[0][j])
				return T[i].func;
		}
	}
	return NULL;
}

