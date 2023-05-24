#ifndef SELL_H
#define SELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
void puts_func(char *str);
void exit_func(char **arv);
int atoi_func(char *s);
void envir_func(char **arv __attribute__ ((unused)));
void set_env_func(char **arv);
void u_setenv_func(char **arv);
void(*built_chek_func(char **arv))(char **arv);
char **to_split_str_func(char *str, const char *delim);
void exe_func(char **argv);
void *realloc_func(void *ptr, unsigned int old_size, unsigned int new_size);
void fre_arv_func(char **arv);
char *get_env_func(const char *name);


/**
 * struct path_link_func - function thatLinked list containing PATH directories
 *
 * @dir: is the directory in path
 * @p: is the pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

list_path *add_node_end_func(list_path **head, char *str);
list_path *linkpath(char *path);
char *fil_which_func(char *filename, list_path *head);
void list_free_func(list_path *head);
char *strdup_func(char *str);
char *all_func(char *name, char *sep, char *value);
char **splitstring(char *str, const char *delim);
void execute(char **argv);
int strlen_func(char *s);
int _putchar(char c);
void handle_sgn_func(int num_sign);
void handle_end_file(int len, char *buff);
void isatty_func(void);
int main(void);
typedef struct ourbuild
{
	char *name;
	void (*func)(char **);
} ourbuild;
#endif
