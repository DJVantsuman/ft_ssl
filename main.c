#include "inc/ssl.h"

void printUsage()
{
	printf("%s\n", "This is usage man.");
}

int main(int argc, char const *argv[])
{
	if(argc == 1)
	{
		printUsage();
		exit(0);
	}
	else
		printf("%s\n", "Hello World");
	return 0;
}