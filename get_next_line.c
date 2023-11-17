/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:17 by klopez            #+#    #+#             */
/*   Updated: 2023/11/17 17:22:54 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_cut4stash(char *str, char stash[1024][BUFFER_SIZE + 1], int fd)
{
    int i;
    int j;
    char *tmp;

    j = 0;
    i = 0;
    tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
    ft_strlcpy(tmp, str, BUFFER_SIZE + 1);
    ft_memset(stash[fd], '\0', BUFFER_SIZE + 1);
    while (tmp[i] && tmp[i] != '\n')
        i++;
    if (tmp[i] == '\n')
        i += 1;
    while (tmp[i] != '\0' && j < BUFFER_SIZE)
        stash[fd][j++] = tmp[i++];
    free(tmp);
}

char    *get_next_line(int fd)
{
    char *buffer;
    static char stash[1024][BUFFER_SIZE + 1];
    char *line;
    int bytes;
    bytes = 1;
    line = NULL;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    ft_memset(buffer, '\0', BUFFER_SIZE + 1);
    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (stash[fd] && !line)
            line = ft_strjoin(line, stash[fd]);
        if (ft_boolstrchr(buffer, '\n') == 1)
        {
            line = ft_strjoin(line, buffer);
            ft_cut4stash(buffer, stash, fd);
            line = ft_cutline(line, '\n');
            return (free(buffer), line); 
        }
        else
            line = ft_strjoin(line, buffer);
    }
    if (bytes == 0)
    {
        if (stash[fd] && !line)
            line = ft_strjoin(line, stash[fd]); 
        ft_cut4stash(stash[fd], stash, fd);
        if (!line[0])
        {
            free(line);
            return (NULL);
        }
    }
    line = ft_cutline(line, '\n');
    return (free(buffer), line); 
}

// int main(void)
// {
//     int fd;
    
//     fd = open("texte.txt", O_RDONLY);
//     char *str = get_next_line(fd);
//     while (str != NULL)
//     {
//         printf("%s", str);
//         free(str);
//         str = get_next_line(fd);
//     }
//  }

// int main (void)
// {
//     char s1[] = "Bonjour les amis\nca va?";
//     char s2[1024][BUFFER_SIZE + 1];
//     ft_cut4stash(s1, s2, 2);
//     printf("%s", s2[2]);
// }
