/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:17 by klopez            #+#    #+#             */
/*   Updated: 2023/11/10 20:41:16 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char   *get_next_line(int fd)
{
    char *buffer;
    static char *stash;
    char *line;
    int bytes;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (ft_boolstrchr(buffer, '\n') == 1)
        {
            line = ft_cutline(buffer, '\n');
            return (line);
        }
        else if(ft_boolstrchr(buffer, '\n') == 0)
    }
    return (stash);
}

int main(void)
{
    int fd;
    fd = open("texte.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));

}