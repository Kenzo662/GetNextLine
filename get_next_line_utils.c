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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	totallen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	totallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(sizeof(char) * (totallen));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
    free(s3);
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((sizeof(char) * ft_strlen(s) + 1));
	if (dest == 0)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = s[i];
	return (dest);
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
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		return(NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			tmp[i] = str[i];
			return(tmp);
		}
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}

char	*ft_cutline2(char *str, char c)
{
	int i;
	int j;
	int count;
	char *tmp;

	count = 0;
	i = 0;
	while (str[count] && str[count] != c)
		count++;
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		return(NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			while(str[i])
			{
				tmp[j] = str[i];
				j++;
				i++;
			}
			return (tmp);
		}
		i++;
	}
	return (tmp);
}




int main (void)
{
	printf("%s\n", ft_cutline2("Bonjour", 'o'));
}