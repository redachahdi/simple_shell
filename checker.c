#include "shell.h"

/**
* built_check_func - function that checks .
*
* @arv: is the array of the arguments
*
* Return: is the pointer
*/
void(*built_check_func(char **arv))(char **arv)
{
	int i, j;
	ourbuild T[] = {
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
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
