#include "main.h"

/**
* checkbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*built_chek_func(char **arv))(char **arv)
{
	int a;
	int b;
	ourbuild M[] = {
		{"exit", exit_func},
		{"env", envir_func},
		{"setenv", set_env_func},
		{"unsetenv", u_setenv_func},
		{NULL, NULL}
	};

	for (a = 0; M[a].name; a++)
	{
		b = 0;
		if (M[a].name[b] == arv[0][b])
		{
			for (b = 0; arv[0][b]; b++)
			{
				if (M[a].name[b] != arv[0][b])
					break;
			}
			if (!arv[0][b])
				return (M[a].func);
		}
	}
	return (0);
}

