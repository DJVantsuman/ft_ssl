#include "../inc/ssl.h"

void printUsage()
{
	printf("%s\n", "This is usage man.");
}

int readFromFile(char *fileName, t_container **var)
{
	char 	*str;
	char 	*tmp;
	char 	buffer[101];
	size_t 	i;
	int 	fd;

	str = "";
	fd = open(fileName, O_RDONLY);
    printf("%s\n",  "readFromFile");
    if (fd > 0)
    {
        while ((i = read(fd, &buffer, 100)) > 0)
        {
            tmp = str;
            buffer[i] = '\0';
            str = ft_strjoin(tmp, buffer);
            ft_strdel(&tmp);
        }
        (*var)->message = str;
    }
    else
        return (-1);
    return (1);
}

char *readFromConsole()
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

int getMessages(t_container **container)
{
    t_container *var;

    var = *container;
    while(var)
    {
        if (var->flag == 'p')
            var->message = readFromConsole();
        else if (var->flag == 'f')
            if (readFromFile(var->fileName, &var) < 0)
            {
                printf("ERROR: Can't open file %s .\n",  var->fileName);
                return (-1);
            }
        var = var->next;
    }
    return (1);
}

void    print(t_container *container)
{
    t_container *var;

    var = container;
    while (var) {
        if(var->message)
            printf("Flag = %c; Message = %s\n", var->flag, var->message);
        else
            printf("Flag = %c; Message = %s\n", var->flag, "NULL");
        var = var->next;
    }
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
        char *s = readFromConsole();
		printf("%d  %s\n", type, s);
	}
	else if(argc > 2)
    {
		checkArguments(argc, argv, &container);
        getMessages(&container);
    }

    print(container);


//	char *s = readFromFile(argv[1]);
//	printf("%d  %s\n", type, s);
	return 0;
}
