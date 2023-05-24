#include "main.h"

/**
 * main -  is the simple shell
 *
 * @argc: is the argument count
 * @argv: is the argument value
 *
 * Return: is the the exit value by status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int nombre = 0, etat = 1, ss = 0;

	if (argv[1] != NULL)
		file_reader(argv[1], argv);
	signal(SIGINT, handl_sign);
	while (etat)
	{
		nombre++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = getline_func();
		if (input[0] == '\0')
		{
			continue;
		}
		history_func(input);
		cmd = commod_parse(input);
		if (strcmp_func((cmd[0], "exit") == 0)
				{
				exit_bul_func(cmd, input, argv, nombre);
				}
		else if (check_builtin_func(cmd) == 0)
		{
			ss = built_hand(cmd, ss);
			free_all(cmd, input);
			continue;
		}
		else
		{
			ss = check_cmd(cmd, input, nombre, argv);

		}
		free_all(cmd, input);
	}
	return (etat);
}
/**
 * check_builtin_func - is the function to check 
 *
 * @cmd:is the command to check
 *
 * Return: if 0 is Succes  if -1 is fail
 */
int check_builtin_func(char **cmd)
{
	bul_t func[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int k = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((func + k)->command)
	{
		if (strcmp_func((cmd[0], (func + k)->command) == 0)
			return (0);
		k++;
	}
	return (-1);
}
/**
 * creat_envi_func -  is function to creat array of enviroment
 * 
 * @envi: is the array
 *
 * Return: is Void
 */
void creat_envi_func(char **env)
{
	int k;

	for (k = 0; environ[k]; k++)
		env[k] = strdup_func(environ[k]);
	env[k] = NULL;
}

