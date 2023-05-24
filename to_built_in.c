#include "main.h"
/**
 * built_exit - function to exit the statut.
 * 
 * @cmd: is the Parse cmd
 * @input: is the user input
 * @argv:is the program name
 * @c: is the excute 
 *
 * Return: is  the void 
 */
void  built_exit(char **cmd, char *input, char **argv, int c)
{
	int etat, k = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][k])
	{
		if (isalpha_func(cmd[1][k++]) != 0)
		{
			p_rerror(argv, c, cmd);
			break;
		}
		else
		{
			etat = atoi_func(cmd[1]);
			free(input);
			free(cmd);
			exit(etat);
		}
	}
}


/**
 * direc_change - function to Change Directory
 *
 * @cmd: is the Parse.
 * @er: is the statue of the Last Command .
 *
 * Return: if 0 is the Succes if 1 is Failed .
 */
int direc_change(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (strcmp_func(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * envir_disply - function to display enviroment of the variable
 *
 * @cmd: is the parse
 * @er: is the Statue
 *
 * Return:Always 0
 */
int envir_disply(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t k;
	int lengh;

	for (k = 0; environ[k] != NULL; k++)
	{
		lengh = lengh_strg(environ[k]);
		write(1, environ[i], lengh);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * h_to_display - function to display help
 *
 * @cmd: is the Parse.
 * @er: is the Statue of the last
 *
 * Return: if 0 is the Succes if -1 is Fail
 */
int h_to_display(char **cmd, __attribute__((unused))int er)
{
	int d, w, r = 1;
	char ch;

	d = open(cmd[1], O_RDONLY);
	if (d < 0)
	{
		perror("Error");
		return (0);
	}
	while (r > 0)
	{
		r = read(d, &ch, 1);
		w = write(STDOUT_FILENO, &ch, r);
		if (w < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 *  cases_echo - is the function to excute echo cases
 * @st: is the statue of last command 
 * @cmd: is the Parse
 *
 * Return: is 0 Or the normal echo
 */
int cases_echo(char **cmd, int sat)
{
	char *_path;
	unsigned int  pid = getppid();

	if (strcmp_func(cmd[1], "$?", 2) == 0)
	{
		number_in_printer(sat);
		PRINTER("\n");
	}
	else if (strcmp_func(cmd[1], "$$", 2) == 0)
	{
		number_printer(pid);
		PRINTER("\n");

	}
	else if (strcmp_func(cmd[1], "$_PATH", 5) == 0)
	{
		_path = envr_get("_PATH");
		PRINTER(path);
		PRINTER("\n");
		free(_path);

	}
	else
		return (echos_printer(cmd));

	return (1);
}
