/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:23:49 by klopez            #+#    #+#             */
/*   Updated: 2023/11/18 20:05:34 by klopez           ###   ########.fr       */
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

int	ft_boolstrchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}


// char	*ft_cutline(char *str, char c)
// {
// 	int i;
// 	int count;
// 	char *tmp;

// 	count = 0;
// 	i = 0;
	
// 	while (str[count] && str[count] != c)
// 		count++;
// 	tmp = malloc(sizeof(char) * (count + 2));
// 	if (!tmp)
// 		return(NULL);
// 	while (str[i] && str[i] != c)
//     {
//         tmp[i] = str[i];
//         i++;
//     }
// 	tmp[i] = str[i];
// 	tmp[i + 1] = '\0';
// 	if (str)
// 		free(str);
// 	return (tmp);
// }

char    *ft_cutline(char *str, char c)
{
    int     i;
    char    *newstr;

    if(!str)
        return(NULL);
    i = 0;
    while (str[i] != c && str[i])
        i++;
    if(str[i] == c)
        i++;
    newstr = ft_calloc(sizeof(char), i + 1);
    if(!newstr)
        return(NULL);
    ft_memcpy(newstr, str, i);
    free(str);
    return(newstr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0',count * size);
	return ((void *)temp);
}
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*dest_temp;
	const char	*src_temp;
	dest_temp = dest;
	src_temp = src;
	if (!dest_temp && !src_temp)
		return (NULL);
	while (len-- > 0)
		*dest_temp++ = *src_temp++;
	return (dest);
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size == 0)
	{
		return (j);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}





// int main (void)
// {
// 	printf("%s\n", ft_cutline2("Bonjour", 'o'));
// }