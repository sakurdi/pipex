#include "pipex.h"

static int	is_sep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static char	**alloc_tab(const char *s, char c)
{
	int		nalloc;
	char	**tab;

	nalloc = 0;
	while (*s)
	{
		if (((*s != c && is_sep(*(s + 1), c))
				|| (*s != c && is_sep(*(s + 1), '\0'))))
			nalloc++;
		s++;
	}
	tab = malloc(sizeof(char *) * (nalloc + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static void	slice_copy(char const *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	alloc_word(char **tab, char const *s, char c, int *counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (is_sep(s[i], c))
			i++;
		else
		{
			j = i;
			while (!is_sep(s[j], c))
				j++;
			tab[*counter] = malloc(sizeof(char) * ((j - i) + 1));
			if (!tab[*counter])
				return (0);
			slice_copy(&s[i], tab[*counter], j - i);
			(*counter)++;
			i = j;
		}
	}
	tab[*counter] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		res;
	int		counter;

	counter = 0;
	tab = alloc_tab(s, c);
	if (!tab)
		return (NULL);
	res = alloc_word(tab, s, c, &counter);
	if (res == 0)
	{
		while (--counter >= 0)
			free(tab[counter]);
		free(tab);
		return (NULL);
	}
	return (tab);
}