#include "main.h"

int check_command_type(char *command)
{
	//Internal Commands
	char *builtins[] = {"echo","printf","read","pwd","pushd","popd","dirs","let","eval","set","unset","export","declare","typeset","readonly","getopts","source","exit","exec","shopt","caller","true","type","hash","bind","help",NULL};
	
	//check whether there is no command	
	if(strcmp(command,"\0") == 0)
	{
		return NO_COMMAND;
	}
	
	//check if the command is builtin
	for(int i=0;builtins[i] != NULL;i++)
	{
		if(strcmp(command,builtins[i]) == 0)
		{
			return BUILTIN;
		}
	}
	//Extract the external commands
	char *external_commands[155] = {NULL};
	extract_external_commands(external_commands);
	
	
	//check if the command is external
	for(int i=0;external_commands[i] != NULL;i++)
	{
		if(strcmp(command,builtins[i]) == 0)
		{
			return BUILTIN;
		}
	}
}


