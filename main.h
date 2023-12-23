#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

int _isspace(char c);
char *trim_whitespace(const char *str);
int check_alias_syntax(const char *input);
int _alias_strcmp(const char *s1, const char *s2, size_t n);
int check_alias(data_shell *datash, char *input);
void add_alias(data_shell *datash, char *alias_name, char *alias_value);
int parse_alias_command(const char *input, char ***alias_names, char ***alias_values);
int parse_alias_command(const char *input, char ***alias_names, char ***alias_values);
int (*get_builtin(char *cmd))(data_shell *);
int cd_shell(data_shell *datash);
int _print(char *string);
void cd_dot(data_shell *datash);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

#endif