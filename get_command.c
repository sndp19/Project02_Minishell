#include "main.h"

//To extract the command until space or a new line is encountered
char *get_command(char *input_string)
{

	//Declare an array to store the command
	static char command[25] = {'\0'};
	int i = 0;
	while(1)
	{
		if(*input_string == ' ' || *input_string == '\n')
		{
			break;
		}
		command[i++] = *input_string;
		input_string++;

	}
	command[i] = '\0';
	return command;

}
