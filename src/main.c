#include "../inc/ssl.h"

void printUsage()
{
	printf("%s\n", "This is usage man.");
}

char *readFromFile(char *fileName)
{
	char 	*str;
	char 	*tmp;
	char 	buffer[101];
	size_t 	i;
	int 	fd;

	str = "";
	fd = open(fileName, O_RDONLY);
	printf("%s\n",  "reedFromConsole");
	while ((i = read(fd, &buffer, 100)) > 0)
	{
		tmp = str;
		buffer[i] = '\0';
		str = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	return (str);
}

char *reedFromConsole()
{
	char 	buffer[101];
	char 	*str;
	char 	*tmp;
	size_t 	i;

	str = "";
	printf("%s\n",  "reedFromConsole");
	while ((i = read(0, &buffer, 100)) > 0)
	{
		tmp = str;
		buffer[i] = '\0';
		str = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	return (str);
}

int main(int argc, char *argv[])
{
	t_container *container;

	container = NULL;
	if(argc == 1)
		printUsage();
	else if(argc == 2)
	{
		getCommand(argv[1]);
		char *s = reedFromConsole();
		printf("%d  %s\n", type, s);
	}
	else if(argc > 2)
		checkArguments(argc, argv, &container);




	char *s = readFromFile(argv[1]);
	printf("%d  %s\n", type, s);
	return 0;
}