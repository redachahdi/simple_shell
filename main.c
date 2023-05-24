#include "main.h"


/**
 * handle_sgn_func - function that checks if Ctrl C is pressed
 *
 * @num_sign: the integer value of the signal
 * Return: void
 */
void handle_sgn_func(int sig_num)
{
	if (sig_num == SIGINT)
	{
		puts_func("\n#cisfun$ ");
	}
}

/**
 * handle_end_file - function that handles the end of file
 *
 * @len: the return value of the get_line function
 * @buff: the buffer
 *
 * Return: void
 */
void handle_end_file(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			puts_func("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * isatty_func - function that checks if the input is coming from a terminal
 *
 * Return: void
 */
void isatty_func(void)
{
	if (isatty(STDIN_FILENO))
		puts_func("#cisfun$ ");
}

/**
 * main - function of the simple Shell
 *
 * Return: if 0 is success
 */
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, handle_sgn_func);
	while (len != EOF)
	{
		isatty_func();
		len = getline(&buff, &size, stdin);
		handle_end_file(len, buff);
		arv = to_split_str_func(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = get_env_func("PATH");
			head = linkpath(value);
			pathname = fil_which_func(arv[0], head);
			f = built_chek_func(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	list_free_func(head);
	fre_arv_func(arv);
	free(buff);
	return (0);
}

