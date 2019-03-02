#include "../inc/ssl.h"

void printUsage()
{
	printf("%s\n", "This is usage man.");
    exit(0);
}

int readFromFile(char *fileName, t_container **var)
{
	char 	*str;
	char 	*tmp;
	char 	buffer[101];
    int 	i;
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
    int 	i;

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
        {
            if (readFromFile(var->fileName, &var) < 0)
            {
                printf("ERROR: Can't open file %s .\n",  var->fileName);
                return (-1);
            }
        }
        if (var->message)
            var->message_len = ft_strlen(var->message);
        var = var->next;
    }
    return (1);
}

void    print(t_container *container)
{
    t_container *var;

    var = container;
    printf("Command = %d\n", type);
    while (var) {
        if(var->message)
            printf("Flag = %c; Message = %s\n",  var->flag, var->message);
        else
            printf("Flag = %c; Message = %s\n",  var->flag, "NULL");
        var = var->next;
    }
}

int main(int argc, char *argv[])
{
	t_container *container;
    t_container *var;

	container = NULL;
    var = newLst(NULL);
	if(argc == 1)
		printUsage();
    else if(argc == 2) // проверить команду на коректность
	{
        var->flag = 'p';
        addLst(&container, var);
	}
    else if(argc > 2) // проверить команду на коректность
        checkArguments(argc, argv, &container);
    getCommand(argv[1]);
    getMessages(&container);
//    print(container);

    if (type == HASH_MD_5)
        calculateMd5(&container);
    else if (type == HASH_SHA256)
        calculateSHA256(&container);
	return 0;
}
