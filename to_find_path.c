#include "main.h"

/**
 * cmd_to_path -  function to search In path
 *
 * @cmd: is the parse
 *
 * Return: if is 1  Failure  if 0 is  Success.
 */
int cmd_to_path(char **cmd)
{
	char *pth, *value, *cd_pth;
	struct st_at bu_f;

	path = envr_get("PATH");
	value = token_string(pth, ":");
	while (value != NULL)
	{
		cd_pth = build_func(*cmd, value);
		if (st_at(cd_pth, &bu_f) == 0)
		{
			*cmd = strdup_func(cd_pth);
			free(cd_pth);
			free(pth);
			return (0);
		}
		free(cd_pth);
		value = token_string(NULL, ":");
	}
	free(pth);

	return (1);
}
/**
 * build_func - function to build cmd
 *
 * @token: is the excute
 * @value: is the directory 
 *
 * Return: is the parse
 */
char *build_func(char *token, char *value)
{
	char *cmd;
	size_t lengh;

	lengh = strlen_func(value) + strlen_func(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset_func(cmd, 0, lengh);

	cmd = strcat_func(cmd, value);
	cmd = strcat_func(cmd, "/");
	cmd = strcat_func(cmd, token);

	return (cmd);
}
/**
 * envr_get - function to get the value
 *
 * @name: is the environment variable name
 *
 * Return: is the the value
 */
char *envr_get(char *name)
{
	size_t n_l, v_l;
	char *value;
	int a, b, c;

	n_l = strlen_func(name);
	for (a = 0 ; environ[a]; a++)
	{
		if (strcmp_func(name, environ[i], n_l) == 0)
		{
			v_l = strlen_func(environ[a]) - n_l;
			value = malloc(sizeof(char) * v_l);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			c = 0;
			for (b = n_l + 1; environ[a][b]; b++, c++)
			{
				value[c] = environ[a][b];
			}
			value[b] = '\0';

			return (value);
		}
	}

	return (NULL);
}
