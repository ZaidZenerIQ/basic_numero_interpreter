#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//a = 3
//b = "zaid"
//c = "3z"
//e = "2"
//ff = 23
//ff = "zaid"
//get(pi) << not var
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
void see_var(char *str,char name[100][100],char value[100][100],bool *num,int n){
	int k = 0;
	int q = 0;
	int l = 0;
	char vstr[100][100];
	char tstr[100];
	char swap[100];
	for(int i =0;i<strlen(str);i++){
	if(str[i]>=47){
	       if(str[i]>'9'){
		       sprintf(vstr[k]+strlen(vstr[k]),"%c",str[i]);
	       } else k++; } }
	for(int i = 0;i<k;i++){
		for(int j = 0;j<n;j++){
			if(strcmp(vstr[i],name[j])==0){
			//	printf("%d %s = %s\n",i,vstr[i],value[i]);
				//_______
				for(int j = 0;j<strlen(str);j++){
					if(str[j]==vstr[q][i]){
						tstr[l] = value[i][j];
					}
					else{
						tstr[l]= str[j]; 
					}
					l++;
				}
				//_______
			}
			//printf("%s %s \n",vstr[i],name[j]);
		}
		vstr[i][0] = '\0';
	}
	printf("> %s\n",tstr);
	//printf("%s\n",vstr[0]);
	//printf("%s\n",vstr[1]);
	printf("\n");
	tstr[0] = '\0';
}
