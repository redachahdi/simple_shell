#include "main.h"

/**
 * built_hand - function to handle built command
 *
 * @cmd: is the parse
 * @er: is the statue
 *
 * Return: if -1 is fail if 0 is succes
 */

int built_hand(char **cmd, int er)
{
	 bul_t bilt[] = {
		{"cd", direc_change},
		{"env", envir_disply},
		{"help", h_to_display},
		{"echo", cases_echo},
		{"history", dist_histor},
		{NULL, NULL}
	};
	int k = 0;

	while ((bilt + k)->command)
	{
		if (strcmp_func(cmd[0], (bilt + k)->command) == 0)
		{
			return ((bilt + k)->fun(cmd, er));
		}
		k++;
	}
	return (-1);
}
/**
 * cmd_to_chek - function to excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd: is the Parse
 * @input: is the User input
 *
 * @c: is the shell excution 
 * @argv: is the program name
 *
 * Return: if 1 is  Case Command Null -1 is fail if 0 is excuted
 */
int cmd_to_chek(char **cmd, char *input, int c, char **argv)
{
	int sat;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (strcmp_func(*cmd, "./", 2) != 0 && strcmp_func(*cmd, "/", 1) != 0)
		{
			cmd_to_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			eror_print(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&sat);
	return (0);
}
/**
 * handl_sign - function to handle
 *
 * @sig: is the capture signal
 *
 * Return: is the Void
 */
void handl_sign(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
