#include <stdio.h>
#include <stdbool.h>

//a = 3
//b = "zaid"
//c = "3z"
//e = "2"
//ff = 23
//ff = "zaid"
//get(pi) << not var
bool var_checker(char *str_in){
	int i = 0;
	bool sif = false;
	char str_t[100];
	while(str_in[i] != '\0'){
	//	printf("%c\n",str_in[i]);
		if(str_in[i] == '=') sif = true;
		if(!sif){
		//	printf(">%c\n",str_in[i]);
		//	str_t[i] = str_in[i];
		}
		i++;
	}	
	return 1;
}
