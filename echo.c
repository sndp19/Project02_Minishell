#include "main.h"


void echo(char *input_string,int status)
{
	//echo $?,echo $$,echo $SHELL
	//echo $?------?How the previous command executed
	if(strncmp(input_string,"echo $?", 7) == 0)
	{

		printf("%d\n",status);
	
	}
	//echo $$
	
	if(strncmp(input_string,"echo $$", 7) == 0)
	{

		printf("%d\n",getpid());
	}

	//echo $SHELL
	
	if(strncmp(input_string,"echo $SHELL", 11) == 0)
	{

		system("pwd");
	}  



}
