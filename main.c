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

int parse_params(char **av, char **envp)
{
	if(!check_files)
		return 0;
	return 1;

}

int main(int ac, char **av, char **envp)
{
	if(ac != 4)
	{
		printf("Wrong number of arguments\n");
		return 0;
	}
	
	
}