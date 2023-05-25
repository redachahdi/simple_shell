#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

char **r_make_env_func(char **env);
void r_free_env_func(char **env);

ssize_t _puts_func(char *str);
char *_strdup_func(char *strtodup);
int _strcmpr_func(char *strcmp1, char *strcmp2);
char *_strcat_func(char *strc1, char *strc2);
unsigned int _strlen_func(char *str);

char **r_tokenize_func(char *buffer, char *delimiter);
char **_realloc_func(char **ptr, size_t *size);
char *r_new_strtok_func(char *str, const char *delim);

void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void r_new_exit_func(vars_t *vars);
void _env_func(vars_t *vars);
void r_new_setenv_func(vars_t *vars);
void r_new_unsetenv_func(vars_t *vars);

void r_add_key_func(vars_t *vars);
char **r_find_key_func(char **env, char *key);
char *r_add_value_func(char *key, char *value);
int _atoi_func(char *str);

void r_check_for_path_func(vars_t *vars);
int r_path_execute_func(char *command, vars_t *vars);
char *r_find_path_func(char **env);
int r_execute_cwd_func(vars_t *vars);
int r_check_for_dir_func(char *str);

void r_print_error_func(vars_t *vars, char *msg);
void _puts2_func(char *str);
char *_uitoa_func(unsigned int count);

#endif
