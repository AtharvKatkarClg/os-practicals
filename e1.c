#include <stdio.h>

int main(){
	FILE *fp;
	char ch, str[100], strl;
	int words=0, lines=0, chars=0;
	fp = fopen("names.txt", "r");
	if(fp == NULL){	
		printf("Error opening file \n");
		return 0;
	}
	
	while ((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
		if(ch == ' ' || ch == '\n')
			words++;
		if(ch == '\n')
			lines++;
		if(ch != ' ' || ch != '\n')
			chars++;
	}
	
	printf("Words\t%d\n", words);
	printf("Lines\t%d\n", lines);
	printf("Characters\t%d\n", chars);
	
	/*while (fgets(str, sizeof(str), fp) != '\0'){
		printf("%s", str);
	}*/
	
	fclose(fp);
}
