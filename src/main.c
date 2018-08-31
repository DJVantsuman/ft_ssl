#include "../inc/ssl.h"

void printUsage()
{
	printf("%s\n", "This is usage man.");
}

int main(int argc, char *argv[])
{
	t_container container;

	if(argc == 1)
		printUsage();
	else if(argc == 2)
		getCommand(argv[1]);
	else if(argc > 2)
		checkArguments(argc, argv, &container);

	return 0;
}