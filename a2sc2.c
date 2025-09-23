#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void make_tok(char *cmd, char *args[]){
	char *p = strtok(cmd, " ");
	int i=0;
	while (p != NULL){
		args[i++]=p;
		p=strtok(NULL, " ");
	}
}

void search(char *fn, char op, char *pat){
	FILE *fp = fopen(fn, "r");
	char word[100];
	int patC=0, lc=0;
	if(fp == NULL){
		printf("Failed to open file\n");
		exit(0);
	}
	
	while(fgets(word, 100, fp) != NULL){
		if(strstr(word, pat) != NULL){
			patC++;
			if(op == 'a')
				printf("%s occured on %d\n", pat, lc+1);
			if(op == 'f')
				break;
		}
		if(strcmp(word,"\n") || strcmp(word,"\0")){
			lc++;		
		}
	}
	
	if(op == 'c'){	
			printf("%s found in file %d times\n", pat, patC);
	}
	
	if(op == 'f'){	
			printf("%s found in file on line %d\n", pat, lc+1);
	}
}

void main(){
	char cmd[100], *args[20];
	int pid;
	while (1){
		fflush(stdin);
		printf("myshell$ ");
		fgets(cmd, 100, stdin);
		cmd[strlen(cmd)-1]='\0';
		make_tok(cmd, args);
		//printf("Provided command %s %s %s %s", args[0],args[1],args[2],args[3]);
		if(strcmp(args[0], "search")==0){
			search(args[2], args[1][0], args[3]);
		} else {
			printf("Invalid command\n");
		}
	}
}
