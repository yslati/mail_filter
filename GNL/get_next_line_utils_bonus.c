#include "get_next_line_bonus.h"

size_t	len_if(char *s, int nl)
{
	size_t	l;

	l = 0;
	if (!nl)
		while (s[l])
			l++;
	else
		while (s[l] && s[l] != '\n')
			l++;
	return (l);
}

char	*ft_dup_free(char *src, char **to_free)
{
	int		l;
	int		i;
	char	*dup;

	if ((l = len_if(src, 0)) == 0)
	{
		if (*to_free)
		{
			free(*to_free);
			*to_free = NULL;
		}
		return (NULL);
	}
	if (!(dup = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = -1;
	while (++i < l)
		dup[i] = src[i];
	dup[i] = '\0';
	if (*to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (dup);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		l1;
	size_t		l2;
	char		*res;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	l1 = len_if(s1, 0);
	l2 = len_if(s2, 1);
	if (!(res = (char *)malloc((l1 + l2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < l1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2 && s2[i] != '\n')
	{
		res[i + l1] = s2[i];
		i++;
	}
	res[i + l1] = '\0';
	return (res);
}

int		build_line(char **line, char **buff, char **buff_s, char step)
{
	char	*tmp;
	char	*par;

	if (step == 0)
		par = *buff_s;
	else
		par = *buff;
	tmp = ft_strjoin(*line, par);
	free(*line);
	*line = tmp;
	if ((tmp = ft_strchr(par, '\n')) != NULL)
	{
		if (step == 0)
		{
			*buff_s = ft_dup_free(tmp + 1, buff_s);
			free(*buff);
		}
		else if (step == 1)
			*buff_s = ft_dup_free(tmp + 1, buff);
		return (1);
	}
	free(*buff_s);
	*buff_s = NULL;
	return (0);
}
