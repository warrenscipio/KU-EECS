#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/mman.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>






//with this the program does not allow to change to directories that have a white space
char *nospace(char *str)//function that removes everywhitespace in the str
{
  char *end;
  while(isspace(*str)) str++;

  if(*str == 0) return str;
  end = str + strlen(str) - 1;
  
  while(end > str && isspace(*end)) end--;
  *(end+1) = 0;

  return str;
}

struct task {// task structure that contains the task id, its pid and the command that it will execute
	int pid;
	int taskid;
	char * command;
};

static int *task_counter;//global counter for the number of tasks in execution
static struct task tasks[100];//array that contains the different tasks


void listoftasks() {//function that will print all the current processes including the background_string
	int i;
	for(i=0; i< *task_counter; i++) {
		if(kill(tasks[i].pid, 0) == 0) {
			printf("[%d] %d %s\n", tasks[i].taskid, tasks[i].pid, tasks[i].command);
		}
	}
}




void execute(char * user_input) {//will verify for any user_input redirection and it will execute the user_input
	int status;
	char * current_user_input = strdup(user_input);
	char * usrinput1 = strtok(user_input," \n");
	int background_string_stat = strlen(usrinput1);
	char * s; char * d;
  	for (s=d=current_user_input;*d=*s;d+=(*s++!='\n')); //remove newline
	strncpy(current_user_input, &current_user_input[background_string_stat + 1], strlen(current_user_input));
	pid_t pid_1;
	pid_1 = fork();
	if (pid_1 == 0) {
		// IO redirection
		if(strchr(current_user_input, '>') != NULL) {
			char *e = strchr(current_user_input, '>');
			int index = (int)(e - current_user_input);
			char *output = strdup(user_input);
			strncpy(output, &current_user_input[index+2], strlen(current_user_input));
			
			
			int out = open(output, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			
			dup2(out,1);
			close(out);
			current_user_input[index-1] = '\0';
		} else if(strchr(current_user_input, '<') != NULL) {
			char *e = strchr(current_user_input, '<');
			int index = (int)(e - current_user_input);
			char *user_inputStream = strdup(current_user_input);
			strncpy(user_inputStream, &current_user_input[index+2], strlen(current_user_input));
			
			
			int in = open(user_inputStream, O_RDONLY);
			dup2(in, 0);
			close(in);
			current_user_input[0] = '\0';
		}
		//end of IO redirection
		if (strlen(current_user_input) > 0) {
			if(execlp(usrinput1, usrinput1, current_user_input, NULL) < 0) {
				fprintf(stderr, "That is an invalid command,jeez\n");
				exit(0);
			} 
		} else {
			if(execlp(usrinput1, usrinput1, NULL) < 0) {
				fprintf(stderr, "That is an invalid command,jeez\n");
				exit(0);
			}
		}
	} else {
		waitpid(pid_1, &status, 0);
		if(status == 1) {
			fprintf(stderr, "%s\n", "Nope");
		}	
	}
}






void cd(const char* path){
 	if(path == NULL){
 		if(chdir(getenv("HOME")) == -1){
 			printf("<%s> is not a working pathname.\n", strerror(errno));
 			 printf("does not allow to change to directories that have a white space\n");
 		}
 	}else{
 		if(chdir(path) == -1){
 			printf("<%s> is not a working pathname.\n", strerror(errno));
 			 printf("does not allow to change to directories that have a white space\n");
 		}
 	}
 }

void parser(char *user_input) {
	char * s; char * d;
	int pipefd_1[2];//pipe array
	char * current_user_input = strdup(user_input); //create copy of the user_input
	int i = 0;
	char * usrinput1;
  	usrinput1 = strtok(user_input," \n=");//returns the user_input until the new line character
  	char * current_command = strdup(usrinput1);//copy the user_input without the new line to current_command
  	char * background_string = strchr(current_user_input, '&');//background_string becomes a non nullptr if there is a & in the user_input
  	char * pipe_string = strchr(current_user_input, '|');// pipe_string becomes a non nullptr if there is a | in the user_input
  	int set_flag = strcmp("set", usrinput1);//set_flag receives a valid value if there is a set command in the user_input

  	int background_string_stat = background_string - current_user_input;//background_string_stat receives the position for the arguments for the background_string process
  	int pipe_loc = pipe_string - current_user_input;//pipe_loc receives the position for the arguments for creating the pipe
  	for (s=d=current_user_input;*d=*s;d+=(*s++!='\n')); // remove newline

  	if (set_flag == 0) {//if the user_input is set then set the new environment
  		usrinput1 = strtok(NULL," \n=");//returns the first section of the user_input
  		char * userinput2 = strtok(NULL, "\n =");//returns the second section of the user_input
		for (s=d=userinput2;*d=*s;d+=(*s++!='\'')); // remove quotes  		
  		setenv(usrinput1, userinput2, 1);//sets the environment to the one specified in the user_input
  	}

  	//Everything after this part is the execution of programs and redirection
  	//This section will create the pipes to be used in the process
  	if (pipe_string != NULL) {
  		if (pipe(pipefd_1) == -1) {//creates the pipe
  			perror("pipe");
  			exit(1);	
  		}

		//by this part, the user_input is clean and without the new line character
  		//get first part (prior to pipe)
  		char * first_half = strdup(current_user_input);//char array that will contain the first part of the pipe
  		char * second_half = strdup(current_user_input);//char array that will contain the second part of the pipe
  		printf("%d\n", pipe_string);
  		strncpy(first_half, &current_user_input[0], pipe_loc);//assign the proper argument of the pipe to first_half
  		first_half[pipe_loc] = '\0';//assign the null terminator to mark the end of the array
  		strncpy(second_half, &current_user_input[pipe_loc+2], strlen(current_user_input));//assign the proper argument of the pipe to second_half

  		//section that creates the pids for the children
  		pid_t pid_1;
  		pid_t pid_2;

  		//first child process
  		pid_1 = fork();
  		if (pid_1 == 0) {
  			dup2(pipefd_1[1],  STDOUT_FILENO);//redirect the read end of the pipe to standard output
  			parser(nospace(first_half));//recursive call to analyze the first argument of the pipe
  			exit(0);
  		} 

  		//second child process
  		pid_2 = fork();
  		if (pid_2 == 0) {
  			dup2(pipefd_1[0], STDIN_FILENO);//redirect the write end of the pipe to standard user_input
  			parser(nospace(second_half));//recursive call to analyze the second argument of the pipe
  			exit(0);
  		} 

  	} else  if (set_flag != 0) {//the user has selected to set a new path
  		//This section will determine wether the process needs to be on the foreground or on the background
	  	if(background_string == NULL) { // foreground
	  		if (strcmp("cd", usrinput1) == 0) {
	 	  		usrinput1 = strtok(NULL, " \n");//get rid of the new line character
	 	  		cd(usrinput1);//change the current direction
		  	} else if (strcmp( "jobs", usrinput1) == 0) {//list all the background_string tasks
			 listoftasks();
		  	} else {//user_input needs execution
		  		execute(current_user_input);
		  	}
	  	} else if (background_string_stat + 1 == strlen(current_user_input)){  // compare the length of background_string user_input and the length of the current user_input to decide if it is a background_string process
	  		for (s=d=current_user_input;*d=*s;d+=(*s++!='&'));//get rid of the & character
	  		pid_t sid;
	  		pid_t pid_1;
	  		pid_1 = fork();
	  		if (pid_1 == 0) {//first child
				sid = setsid();//creates a new session for sid
				if (sid < 0) {
					printf("failed to create processes\n");
				    exit(EXIT_FAILURE);
				}
				//Close the unused ends of the pipe
	  			close(pipefd_1[0]);
	  			close(pipefd_1[1]);
	  			close(STDIN_FILENO);

	  			//Provide details about the background process
	        	printf("[%d] %d is running in background\n", getpid(), *task_counter);//prints the information of the process running in the background_string
	  			parser(current_user_input);//parses the user_input of the process in order to execute it
	  			printf("[%d] has ended\n", getpid());//after the process is executed then end the background_string process
	  			kill(getpid(), -9);//finally kill the process
	  			exit(0);
	  		} else {//creates a cur task structure  and waits for any child process to end
	  			struct task cur_task = { .taskid = pid_1, .pid = *task_counter, .command =  current_command};
	  		    tasks[*task_counter] = cur_task;
	  			*task_counter =  *task_counter + 1;
	  			int status;
	  			while(waitid(pid_1, NULL, WEXITED|WNOHANG) > 0) {}
	  		}
	  	} else {
	  		//Message whenever the input command does not fit any of the specifications
	  		printf("Be sure the '&' comes after the process you want to run. Please restate.\n");
	  	}
	}
}

int main(int argc, char **argv, char **envp) {
 task_counter = mmap(NULL, sizeof  *task_counter, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	char* user_input, shellmessage[100];
	rl_bind_key('\t', rl_complete);
	 *task_counter = 0;
	char cur_dir[128];
	char * test;
	int i = 0;
    do { 
    	snprintf(shellmessage, sizeof(shellmessage), "{%s@%s}Ⓠ ", getenv("USER"), getcwd(NULL, 1024));//creates the message that will be displayed in the screen when the user opens the shell
        user_input = readline(shellmessage);//gets the user_input while displaying the message
        if (!user_input) break;//if there is no user_input then end the execution
        add_history(user_input);//adds the user to the command history so the user can retrieve them if they want later
        while(waitpid(-1, NULL, WNOHANG) > 0) {}
    	if(strcmp("exit", user_input) != 0 & strcmp("quit", user_input) != 0){//verifies if the user user_inputs the quit or exit command
    		if(strlen(user_input) > 1)  {
    			char * s; char * d;
	  			for (s=d=user_input;*d=*s;d+=(*s++!='\n'));
    			parser(nospace(user_input));//removes any whitespace in the user_input and then analyzes its content
    		}
    	} else {
    		break;
    	}
        free(user_input);
        
    } while (1);

    return 0;
}
