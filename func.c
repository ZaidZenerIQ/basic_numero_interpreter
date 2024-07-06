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
bool check_func(char *str,char func_name[100][100],char *temp){
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
int get_arg(char *str,char *arg){
	bool k = false;
	int j = 0;
	for(int i = 0;i<strlen(str);i++){
		if(str[i]==')') k = false;
		if(k){	
			arg[j] = str[i];
			j++;
		}
		if(str[i]=='(') k = true;
	}
	arg[j] = '\0';
	if(arg[0]=='"' && arg[j-1]=='"') return false;
	else if (arg[0]!='"' && arg[j-1]!='"') return true;
	return 2;
	//error_function()
}
void out_call(char *arg){
	printf("%s\n",arg);
}
void function_call(char *func,char *arg){
	switch (func[0]){
	case 'o':
		out_call(arg);
		break;
	case 's':
	//	printf("sqrt\n");
		break;
	case 'p':
	//	printf("pow\n");
		break;
	}
}
