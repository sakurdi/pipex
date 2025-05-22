#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

size_t ft_strlen(char *s);
char *ft_strdup(char *s);
char	**ft_split(char const *s, char c);

#endif