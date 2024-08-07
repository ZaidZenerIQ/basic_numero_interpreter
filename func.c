#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
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
bool see_arg(char *arg,char *cot){
	bool igf = 0;
	igf = (cot[0] == '"' || cot[strlen(cot)-1] == '"');
	if(igf) return 1;
	else return 0;
}
bool get_arg(char *str,char *arg,bool *ifs){
	// !!
	*ifs = false;
	char cot[5];
	bool k = false;
	int j = 0;
	int q = 0;
	bool e = 0;
	for(int i = 0;i<strlen(str);i++){
		if(str[i]=='\0') k = false;
		if(k && str[i]!='"'){	
			arg[j] = str[i];
			j++;
		}
		else if(k && str[i]=='"'){
			cot[q] = str[i];
			q++;
		}
		if(str[i]=='(') k = true;
	}
	arg[j-1] = '\0';
	cot[q] = '\0';
	e = (cot[0]=='"' && cot[1]=='"');
	if(e) return 1;
	e = see_arg(arg,cot);
	if(e) return 0;
	if(str[0]=='o')*ifs = true;
	return 1;
}
void out_call(char *arg){
	printf("%s\n",arg);
}
void sqrt_call(char *arg,char name[100][100],char value[100][100],int n){
	float f = 0;
	int i = 0;
	for(i = 0;i<n;i++){
		if(strcmp(arg,name[i])==0){
			f = atof(value[i]);
			f = sqrtf(f);
			break;
		}
	}
	sprintf(value[i],"%.0f",f);
}
void pow_call(char *arg,char name[100][100],char value[100][100],int n){
	float f = 0;
	int i = 0;
	for(i = 0;i<n;i++){
		if(strcmp(arg,name[i])==0){
			f = atof(value[i]);
			f = f*f;
			break;
		}
	}
	sprintf(value[i],"%.0f",f);
}
void function_call(char *func,char *arg,char name[100][100],char value[100][100],int n){
	switch (func[0]){
	case 'o':
		out_call(arg);
		break;
	case 's':
		sqrt_call(arg,name,value,n);
		break;
	case 'p':
		pow_call(arg,name,value,n);
		break;
	}
}
