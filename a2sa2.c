#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void list(char *dirname, char op)
{
	DIR *dp;
	int fc=0, dc=0;
	struct dirent *entry;
	dp=opendir(dirname);
	if(dp == NULL){
		printf("Invalid directory name %s \n", dirname);
		exit(0);
	}
	
	switch (op)
	{
		case 'f':
			printf("List files in %s\n", dirname);
			while(entry = readdir(dp)){
				if(entry -> d_type == DT_REG){
					printf("%s\n", entry -> d_name);
				}
			}
			break;
		case 'n':
			while(entry = readdir(dp)){
				if(entry -> d_type == DT_REG)
					fc++;
				if(entry -> d_type == DT_DIR)
					dc++;
			}
			printf("File count: %d\nDirectory count: %d\n", fc, dc);
			break;
		case 'i':
			while(entry = readdir(dp)){
				if(entry -> d_type == DT_REG)
					printf("%s %ld \n", entry -> d_name, entry -> d_fileno);
			}
			break;
	}
}


void main(){
	char cmd[100], t1[20], t2[20], t3[20];
	int pid;
	while(1){
		printf("myshell$ ");
		strcpy(t1, "");
		strcpy(t2, "");
		strcpy(t3, "");
		fflush(stdin);
		fgets(cmd, 100, stdin);
		sscanf(cmd, "%s%s%s", t1,t2,t3);
		//printf("Provided command %s %s %s \n", args[0], args[1], args[2]);
		if(strcmp(t1, "list") == 0){
			list(t3, t2[0]);
		} else {
			pid = fork();
			if(pid > 0){
				wait(NULL);
			}
		}
	}
}
