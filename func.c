#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void built_in_func(char func_name[100][100]){
	char arr[3][10] = {"out()","sqrt()","pow()"};
	for(int i = 0;i<3;i++){
		strcpy(func_name[i],arr[i]);
	}
}
bool check_func(char *str,char func_name[100][100]){
	char temp[100];
	int i = 0;
	while(str[i] != '('){
		temp[i] = str[i];
		i++;
		if(i == strlen(str)) return 0;
	}
	temp[i] = '(';
	temp[i+1] = ')';
	temp[i+2] = '\0';
	for(int i = 0;i<3;i++){
		if(strcmp(temp,func_name[i])==0){
			return 1;
		}
	}
	return 0;
}
