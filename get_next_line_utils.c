/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:23:49 by klopez            #+#    #+#             */
/*   Updated: 2023/11/15 19:02:29 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	size_t	totallen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	totallen = ft_strlen(s2) + 1;
	if (s1)
		totallen += ft_strlen(s1);
	s3 = malloc(sizeof(char) * (totallen));
	if (!s3)
		return (NULL);
	if (s1)
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	if (s1)
		free (s1);
	return (s3);
}

int	ft_boolstrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (0);
	}
	return (0);
}


char	*ft_cutline(char *str, char c)
{
	int i;
	int count;
	char *tmp;

	count = 0;
	i = 0;
	while (str[count] && str[count] != c)
		count++;
	tmp = malloc(sizeof(char) * (count + 2));
	if (!tmp)
		return(NULL);
	while (str[i] && str[i] != c)
    {
        tmp[i] = str[i];
        i++;
    }
	tmp[i] = str[i];
	tmp[i + 1] = '\0';
	if (str)
		free(str);
	return (tmp);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}




// int main (void)
// {
// 	printf("%s\n", ft_cutline2("Bonjour", 'o'));
// }