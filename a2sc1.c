#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void make_token(char *cmd, char *args[]){
	char *p = strtok(cmd, " ");
	int i=0;
	while(p != NULL){
		args[i++]=p;
		p=strtok(NULL, " ");
	}
	args[i]=NULL;
}

void typeline(char *fname, char *op){
	FILE *fp = fopen(fname, "r");
	char ch;
	int lc=1;
	
	int n = atoi(op);
	
	if(fp == NULL) {
		printf("Failed to open file \n");
		exit(0);
	}
	
	
	if(strcmp(op, "a") == 0){
		printf("Printing all lines in the file\n");
		while(((ch = fgetc(fp)) != EOF)){
			printf("%c", ch);
		}
	}

	if(n > 0){
			printf("Printing %d lines in the file\n", n);
			while(((ch = fgetc(fp)) != EOF) && (lc <= n)){
				if(ch == '\0' || ch == '\n')
					lc++;
				printf("%c", ch);
			}
	}
	
	if(n < 0){
			printf("Printing last %d lines in the file\n", n);
			while(((ch = fgetc(fp)) != EOF)){
				if(ch == '\0' || ch == '\n')
					lc++;
			int fl = lc - n;
			printf("Start from line %d\n", fl);
			int nlc = 1;
			while(((ch = fgetc(fp)) != EOF)){
				if(ch == '\0' || ch == '\n')
					nlc++;
					
				if(nlc >= fl)
					printf("%c", ch);
			}
		}
	}
	fclose(fp);
}

void main(){
	char cmd[100], *args[20];
	int pid, n=2;
	
	while(1){
		fflush(stdin);
		printf("myshell$ ");
		fgets(cmd, 100, stdin);
		cmd[strlen(cmd)-1] = '\0';
		make_token(cmd, args);
		//printf("Provided command %s %s %s \n", args[0],args[1],args[2]);
		if(strcmp(args[0], "typeline") == 0){
			typeline(args[2], args[1]);
		}/* else {
			pid = fork();
			if(pid > 0)
				wait(NULL);
			else {
				if(execv(args[0], args) == 0){
					printf("Invalid command\n");
				}
			}
		}*/
	}
}
