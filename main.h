#ifndef _MAIN_H_
#define _MAIN_H
 
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, strlen_func(c)))



extern char **environ;
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

unsigned int delim_to_check(char c, const char *str);
char *token_string(char *str, const char *delimi);
void  built_exit(char **cmd, char *input, char **argv, int c);
int direc_change(char **cmd, __attribute__((unused))int er);
int envir_disply(__attribute__((unused)) char **cmd, __attribute__((unused)) int er);
int h_to_display(char **cmd, __attribute__((unused))int er);
int cases_echo(char **cmd, int sat);
int _putchar(char c);
char *cp_string(char *dest, char *src, int n);
int lengh_strg(char *s);
int atoi_func(char *s);
void puts_func(char *str);
int built_hand(char **cmd, int er);
int cmd_to_chek(char **cmd, char *input, int c, char **argv);
void handl_sign(int sig);
void file_reader(char *filename, char **argv);
void file_treater(char *line, int nombre, FILE *pl, char **argv);
void exit_bul_file_func(char **cmd, char *line, FILE *fd);
int cmd_to_path(char **cmd);
char *build_func(char *token, char *value);
char *envr_get(char *name);
int main(__attribute__((unused)) int argc, char **argv);
int check_builtin_func(char **cmd);
void creat_envi_func(char **env);
void prompt_func(void);
void eror_print(char *input, int nombre, char **argv);
typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;




#endif
