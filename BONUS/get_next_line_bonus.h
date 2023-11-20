/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:28:32 by klopez            #+#    #+#             */
/*   Updated: 2023/11/20 16:28:50 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_boolstrchr(const char *s, char c);
char	*ft_cutline(char *str, char c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_cut4stash(char *str, char stash[1024][BUFFER_SIZE + 1], int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
char	*ft_update4stash(char *buffer, char stash[1024][BUFFER_SIZE + 1],
			char *line, int fd);

#endif