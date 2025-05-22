#include "pipex.h"

int check_files(char *in, char *out)
{
	int fd;

	fd = open(in, O_RDONLY);
	if(fd == -1)
	{
		printf("Couldnt open infile\n");
		return 0;
	}
	close(fd);
	fd = open(out, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if(fd == -1)
	{
		printf("Couldnt create outfile\n");
		return 0;
	}
	close(fd);
	return 1;
}

int ft_strncmp(char *s1, char *s2, size_t n)
{
	while(*s1 == *s2 && n && *s1 && *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return *s1 - *s2;
}

char *get_env(char **envp)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			str = ft_strdup(envp[i + 5]);
			printf("%s\n", str);
		}
		i++;
	}
	return str;
}

int check_args(char *arg1, char *arg2, char **envp)
{
	
}

int parse_params(char **av, char **envp)
{
	if(!check_files || !check_args(av[2], av[3], envp))
		return 0;
	return 1;

}

int main(int ac, char **av, char **envp)
{
	if(ac != 5)
	{
		printf("Wrong number of arguments\n");
		return 0;
	}
	get_env(envp);
	
}