/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:17 by klopez            #+#    #+#             */
/*   Updated: 2023/11/15 19:11:03 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_cut4stash(char *str, char stash[1024][BUFFER_SIZE + 1], int fd)
{
    int i;
    int j;

    j = 0;
    i = 0;
    ft_memset(stash[fd], '\0', BUFFER_SIZE + 1);
    while (str[i] && str[i] != '\n')
        i++;
    i += 1;
    while (str[i] != '\0' && j < BUFFER_SIZE)
        stash[fd][j++] = str[i++];
}

char    *get_next_line(int fd)
{
    char *buffer;
    static char stash[1024][BUFFER_SIZE + 1];
    char *line;
    int bytes;
    line = NULL;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    ft_memset(buffer, '\0', BUFFER_SIZE + 1);
    while (ft_boolstrchr(buffer, '\n') != 1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE + 1);
        if (bytes == 0)  
            return (free(buffer), line);
        if (stash[fd] && !line)
            line = ft_strjoin(line, stash[fd]);
        line = ft_strjoin(line, buffer);
    }
    line = ft_cutline(line, '\n');
    ft_cut4stash(buffer, stash, fd);
    return (line);
}

int main(void)
{
    int fd;
    
    fd = open("texte.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
}

// int main (void)
// {
//     char s1[] = "Bonjour les amis\nca va?";
//     char s2[1024][BUFFER_SIZE + 1];
//     ft_cut4stash(s1, s2, 2);
//     printf("%s", s2[2]);
// }
