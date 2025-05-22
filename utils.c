#include "pipex.h"

int forbidden_chars(char *str)
{
	int i;

	i = 0;
	while(str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if(!str[i])
		return 1;
	i = 0;
	while(str[i])
	{
		if(str[i] == '>' || str[i] == '<' || str[i] == '|')
			return 1;
		i++;
	}
	return 0;
}

size_t ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return i;
}

char *ft_strdup(char *s)
{
	int i;
	char *ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if(!ret)
		return NULL;
	while(s[i])
	{
		ret[i] = s[i];
		i++;
	}
	return ret;
}