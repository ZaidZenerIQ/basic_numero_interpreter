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
	while(str_in[i]!= '='){
		str_out[i] = str_in[i];
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
