#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void make_token(char *cmd, char *args[]){
	int i=0;
	char *p;
	p=strtok(cmd, " ");
	while(p != NULL){
		args[i]=p;
		i++;
		p=strtok(NULL," ");
	}
	args[i]=NULL;
}

void cmd_count(char *fn, char op){
	FILE *fp = fopen(fn, "r");
	int c=0,w=0,l=0;
	char ch;
	
	while((ch = fgetc(fp)) != EOF){
		c++;
		
		if(ch == '\n' || ch == '\0'){
			l++;
		}
		
		if(ch == '\t' || ch == '\n' || ch == '\0' ||ch == ' ' ){
			w++;
		}
	}
	
	fclose(fp);
	
	switch (op){
		case 'l':
			printf("Lines in file: %d", l);
			break;
		case 'w':
			printf("Words in file: %d", w);
			break;
		case 'c':
			printf("Characters in file: %d", c);
			break;
		default:
			printf("Invalid operator supplied (%c)", op);
	}
	printf("\n");
}

void main(){
	char cmd[100], *args[20];
	int pid;
	
	while(1){
		printf("myshell$ ");
		fflush(stdin);
		fgets(cmd, 100, stdin);
		cmd[strlen(cmd)-1] = '\0';
		make_token(cmd, args);
		
		if(strcmp(args[0], "count") == 0){
			cmd_count(args[2], args[1][0]);
		} else {
			pid = fork();
			
			if(pid > 0)
				wait(NULL);
			else {
				if(execvp(args[0], args) == -1)
					printf("Invalid command \n");
			}
		}
	}
}
