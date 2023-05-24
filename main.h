#ifndef MAIN_H
#define MAIN_H


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

int _putchar(char c);
void puts_func(char *str);
int strlen_func(char *s);
char *strdup_func(char *str);
char *all_func(char *name, char *sep,char *value);

char **to_split_str_func(char *str, const char *delim);
void execute(char **argv);
void *realloc_func(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;


/**                                                                      
 * struct path_link_func - function thatLinked list containing PATH dire\
ctories                                                                  
 *                                                                       
 * @dir: is the directory in path                                        
 * @p: is the pointer to next node                                       
 */
typedef struct list_path
{
        char *dir;
        struct list_path *p;
} list_path;

char *get_env_func(const char *name);
list_path *add_node_end_func(list_path **head, char *str);
list_path *linkpath(char*path);
char *fil_which_func(char *filename, list_path *head);

typedef struct ourbuild
{
        char *name;
        void (*func)(char **);
} ourbuild;

void(*built_chek_func(char **arv))(char **arv);
int atoi_func(char *s);
void exit_func(char **arv);
void envir_func(char **arv);
void set_env_func(char **arv);
void u_setenv_func(char **arv);

void fre_arv_func(char **arv);
void list_free_func(list_path *head);


#endif

