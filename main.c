#include "shell.h"

/**
 * _sig_handler - function that checks if Ctrl C is pressed
 *
 * @sig_num: is the int
 * return: is void
 */
void _sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		puts_func("\n$ ");
	}
}

/**
 * _EOF_ - is the functions that handles the End of file
 *
 * @len: that return value of the getline function
 * @buff: is the buffer
 *
 * return: is void
 */
void _EOF_(int len, char *buff)
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
 * _isatty - function that verif if terminal
 * Return: is void
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		puts_func("$ ");
}
/**
 * main - functui of the Shell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, _sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF_(len, buff);
		arv = to_split_str_func(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = get_env_func("PATH");
			head = linkpath(value);
			pathname = fil_which_func(arv[0], head);
			f = built_check_func(arv);
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
