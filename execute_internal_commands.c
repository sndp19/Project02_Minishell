#include "main.h"

void execute_internal_commands(char *input_string)
{
	char *path, *backup_path;

	/*  exit,cd,pwd  */
	//exit
	if(strncmp("exit",input_string,4) == 0)
	{
		exit(1);
	}
	//pwd
	if(strncmp("pwd",input_string,3) == 0)
	{
		system("pwd");
	}
	
	if(strncmp("cd",input_string,2) == 0)
	{
		path = strtok(input_string," ");
		while(path != NULL)
		{
			backup_path = path;
			path = strtok(NULL," ");
		}
		chdir(backup_path);	
	}


}


