#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool var_checker(char *str_in){
	int i = 0;
	while(str_in[i] != '\0'){
		if(str_in[i]=='=') return 1;
		i++;
	}	
	return 0;
}
void get_name_var(char *str_in,char *str_out){
	int i = 0;
	int j = 0;
	while(str_in[i]!= '='){
		if(str_in[i]!=' '){
		str_out[j] = str_in[i];
		j++;
		}
		i++;
	}
}
void get_value_var(char *str_in,char *str_out){
	int i = 0;
	int j = 0;
	bool k = 0;
	while(str_in[i]!='\0'){
		if(str_in[i]=='=') k = 1;
		if(k && str_in[i]!='=' && str_in[i]!=' '){
			str_out[j] = str_in[i];
			j++;
		}
		str_out[j] = '\0';
		i++;
	}
}
bool get_type_var(char *var_in){
	// 1 => num
	// 0 => str
	return (var_in[0]!='"');
}
bool use_var(char *str){
	for(int i = 0;i<strlen(str);i++){
		if(str[i]<47) continue;
		else{
			if(str[i]>='A') return 1;
		}
	}
	return 0;
}
void pars_var(char *str,char *equ,char array_str[100][100],int *j){
	char ts[100] = "\0";
	int k = 0;
        for(int i = 0;i<strlen(str);i++){
                if(str[i]<=47){
			equ[k] = str[i];
                        k++;
                        ts[0] = '\0';
                }
                else{
                        sprintf(ts+strlen(ts),"%c",str[i]);
			strcpy(array_str[k],ts);
                }
        }
	*j = k;

}
void get_tok(bool *arr,char str[100][100],int c){
	for(int i = 0;i<=c;i++){
		arr[i] = (str[i][0]>65);
	}
}
void get_vals(char streq[100][100],char name[100][100],char value[100][100],bool *tok,int c,int n){
	for(int i = 0;i<=c;i++){
		for(int j = 0;j<=n;j++){
			if(tok[i])if(strcmp(streq[i],name[j])==0) strcpy(streq[i],value[j]);
		}
	}
}
void make_equ(char *str,char strq[100][100],char *equ,int c){
	char tstr[100] = "\0";
	for(int i = 0;i<=c;i++){
		strcat(tstr,strq[i]);
		sprintf(tstr+strlen(tstr),"%c",equ[i]);
	}
	tstr[strlen(tstr)] = '\0';
	strcpy(str,tstr);
	for(int i = 0;i<=c;i++){
		for(int j = 0;j<strlen(strq[i]);j++){
			strq[i][j] = '\0';
		}
		equ[i] = '\0';
	}
}

void get_const(char name[100][100],char value[100][100],int *n){
		char const_name[2][10] = {"PI","D_PI"};		
		char const_value[2][10] = {"3.141","6.282"};
		for(int i = 0;i<2;i++){
				strcpy(name[i],const_name[i]);
				strcpy(value[i],const_value[i]);
				*n = *n + 1;
		}
}
