#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calco.h"
#include "vars.h"

struct var_data {
	char var_name[100][100];
	char var_value[100][100];
	bool num[100];
};

int main(int argc,char *argv[]){
	struct var_data var_info;

	if(argv[1]==NULL){
		printf("Nead argument of the name of the file\n");
		return 1;
	}
	else if(argv[1][0]=='-' && argv[1][1]=='h' && argv[2] == NULL){
		printf("-c  print the result in the console\n");
		printf("-cq print the result and its equation in the console\n");
		printf("-f  print the result in  file\n");
		printf("-fq print the result and its equation in file\n");
		return 1;
	}
	else if(argv[2]==NULL){
		printf("Please give the option to how to output the result\n");
		printf("For more info. use -h\n");
		return 1;
	}
	else if(argv[2][0]!='-'){
		printf("Incorrect command \n");
		printf("For more info. use -h\n");
		return 1;
	}
	
	//declartion of Variables
	FILE *fptr;
	FILE *save;
	char out[100];
	char strn[100];
	size_t lines = 0;
	float num = 0;
	bool ifs = false;
	bool vif = false;
	bool vvf = false;
	bool tok[100];
	int n = 0;
	int c = 0;
	char streq[100][100];
	char equ[100];
	int len = 0;
	//reading file
	fptr = fopen(argv[1], "r");
	if(fptr == NULL) {
 		printf("Not able to found this file.\n");
		return 1;
	}
	//main loop
	while(fgets(strn, 100, fptr)){
		strn[strcspn(strn, "\n")] = 0;

		if(!ifs) vif  = var_checker(strn);
		if(vif){
			//will see if there is var. in lines 
			get_name_var(strn,var_info.var_name[n]);
			get_value_var(strn,var_info.var_value[n]);
			var_info.num[n] = get_type_var(var_info.var_value[n]);
			n++;
		}
		if(ifs){
			vvf = use_var(strn); // will check if the equ. use variable
				if(vvf){
					pars_var(strn,equ,streq,&c);
					get_tok(tok,streq,c);
					get_vals(streq,var_info.var_name,var_info.var_value,tok,c,n);
					make_equ(strn,streq,equ,c);
				}
			equle(strn,&num);
		}

		//commmands
		if(argv[2][0] == '-'){
			if(argv[2][1]=='\0'){
				printf("Provid the option to how to output the result\n",num);
				printf("For more info. use -h\n");
				return 1;
			}
			else if(argv[2][1]=='c' && argv[2][2]=='q'&& argv[2][3]=='\0'){
				if(ifs)printf("%s = %.3f\n",strn,num);
			}
			else if(argv[2][1]=='c' && argv[2][2]=='\0'){
				if(ifs == true)printf("%.3f\n",num);
			}
			else if(argv[2][1]=='f'){
					if(argv[3]==NULL){
						printf("Provide the name of file\n");
						return 1;
					}
					else if(argv[3]!=NULL){
						if(lines==1)remove(argv[3]);
						out[100];
						if(argv[2][2]=='q' && argv[2][3]=='\0'){
							if(ifs)sprintf(out,"%s = %.3f\n",strn,num);
						}
						else if(argv[2][2]=='\0') {
							if(ifs)sprintf(out,"%.3f\n",num);
						}
						else{
							printf("this command doesn't exist\n");
							printf("For more info. use -h\n");
							return 1;
						}
						save = fopen(argv[3],"a");
						fputs(out, save);
					}
					fclose(save);
			}
			else {
				printf("this command doesn't exist\n");
				printf("For more info. use -h\n");
				return 1;
			}
		}

		lines++;
		if(strcmp(strn,"_start_")==0)ifs = true;
 	}

	fclose(fptr);

	return 0;
}
