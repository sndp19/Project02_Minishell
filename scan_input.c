#include "main.h"

pid_t ret;
void scan_input(char *prompt,char *input_string)
{
	char *command = '\0';
	int command_type,status,ret_status;
	
	//Registering the signal SIGINT
	signal(SIGINT,signal_handler);
	while(1)
	{
		memset(input_string,'\0',25);

		printf(ANSI_COLOR_RED"[%s]$"ANSI_COLOR_RESET ,prompt);
		//clear the output buffer
		fflush(stdout);
		scanf("%[^\n]s",input_string);
		//clear the input buffer
		getchar();

		//Customize the prompt
		if(!strncmp("PS=",input_string,3)) 				       
		{	//PS1=minishell
			if(input_string[3] !=' ' && input_string[4] !=' ')
			{
				strcpy(prompt,&input_string[4]);
				//Clear the input string
				memset(input_string,'\0',25);
				continue;
			}	
			else
				printf("COMMAND NOT FOUND\n");
			continue;
		}		
		//Get the command
		command = get_command(input_string);
		printf("Command is %s \n",command);

		//check the command whether it's internal, external, no command
		command_type = check_command_type(command);
		if(command_type == EXTERNAL)
		{
			ret = fork();
			if(ret == 0)
			{
				//Child process has to execute the command	
				ret_status=system(input_string);
				if(ret_status == 0)
				{
					exit(0);
				}
				else
					exit(1);				
			}	
			else if(ret >0)
			{
				wait(&status);
				//child terminated or not
				if(WIFEXITED(status))
				{
					printf("Child with pid %d terminated normally \n",ret);

				}	
			} 
			else
			{
				printf("ERROR:fork failed\n");
				exit(1);
			}
			//Call the function to implement echo commands
			echo(input_string,status);
			//Function to implement internal commands
			execute_internal_commands(input_string);
			if((command_type != BUILTIN) && (command_type != EXTERNAL) &&  (command_type != NO_COMMAND))
			{
				printf("Command not found\n");
			}
		}
	}

}



