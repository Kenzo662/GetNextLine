#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5

#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
int	    ft_boolstrchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_cutline(char *str, char c);


#endif