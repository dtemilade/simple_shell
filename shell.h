#ifndef _SHELL_H_

#define _SHELL_H_
extern char **environ;
#define HIST_FILE".simple_shell_history"
#define HIST_MAX4096
#define CONVERT_LOWERCASE1
#define CONVERT_UNSIGNED2
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define USE_GETLINE 0
#define USE_STRTOW 0
#define GOTO_NORM0
#define GOTO_OR1
#define GOTO_AND2
#define GOTO_CHAIN3
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct listint_s - function for singly linked list
 * @n: parameter for integer
 * @next: parameter for points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
int n;
struct listint_s *next;
} listint_t;

/**
 * struct passinfo - function that contains pseudo-arguements
 * @arg: parameter for a string generated from getline containing arguements
 * @argv: parameter foran array of strings generated from arg
 * @path: parameter for a string path for the current command
 * @argc: parameter for the argument count
 * @var_ind: parameter for the error count
 * @err_num: parameter for the error code for exit()s
 * @f_lind: parameter for if on count this line of input
 * @val_f: parameter for the program filename
 * @env: parameter forlinked list local copy of environ
 * @environ: parameter for custom modified copy of environ from LL env
 * @history: parameter for the history node
 * @alias: parameter for the alias node
 * @env_changed: parameter for on if environ was changed
 * @status: parameter for the return status of the last exec'd command
 * @goto_buf: parameter of pointer to goto_buf, on if chaining
 * @goto_buf_type: parameter forGOTO_type ||, &&, ;
 * @readfd: parameter for the fd from which to read line input
 * @ind_hist: parameter for the history line number count
 */
typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int var_ind;
int err_num;
int f_lind;
char *val_f;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;

char **goto_buf;
int goto_buf_type;
int readfd;
int ind_hist;
} info_t;


/**
 * struct builtin - function that contains a builtin string and functions
 * @type: parameter for the builtin command flag
 * @func: parameter for the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;

int _eputchar(char);
int _putsfd(char *str, int fd);
int _strcmp(char *, char *);
int hsh(info_t *, char **);
int _putfd(char c, int fd);
int _grpfnsalias(info_t *);
int var_rep(info_t *);
int a_rep(info_t *);
int s_rep(char **, char *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int _grpfnsunsetenv(info_t *);
int _grpfnsenv(info_t *);
int create_history(info_t *info);
int _grpfnssetenv(info_t *);
int view_history(info_t *info);
int pop_env_list(info_t *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
list_t *addn_end(list_t **, const char *, int);
int _setenv(info_t *, char *, char *);
int _strlen(char *);
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int var_c);
int hist_num(info_t *info);
list_t *add_node(list_t **, const char *, int);
int _grpfnshelp(info_t *);
int _grpfnshistory(info_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
size_t print_list(const list_t *);
size_t print_list_str(const list_t *);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
void free_list(list_t **);
ssize_t getn_index(list_t *, list_t *);
list_t *node_starts_with(list_t *, char *, char);
int deleten_at_index(list_t **, unsigned int);
int is_chain(info_t *, char *, size_t *);
int find_builtin(info_t *);
void clear_info(info_t *);
void set_info(info_t *, char **);
void find_search(info_t *);
void fw_search(info_t *);
int is_search(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loophsh(char **);
void _eputs(char *);
char *_strdup(const char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
void _puts(char *);
int _putchar(char);
char **strtow(char *, char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
char *_strchr(char *, char);
void f_free(char **);
void print_error(info_t *, char *);
void *_realloc(void *, unsigned int, unsigned int);
int b_free(void **);
int interactive(info_t *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _atoi(char *);
int is_delim(char, char *);
int _erratoi(char *);
int _isalpha(int);
int _grpfnsexit(info_t *);
int _grpfnscd(info_t *);

#endif

