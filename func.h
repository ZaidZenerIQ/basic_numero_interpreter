#ifndef __FUNC_H__
#define __FUNC_H__
void built_in_func(char func_name[100][100]);
bool check_func(char *str,char func_name[100][100],char *func);
void function_call(char *func,char *arg,char name[100][100],char value[100][100],int n);
bool get_arg(char *str,char *arg,bool *ifs);
void out_call(char *arg);
bool see_arg(char *arg,char *cot);
void pow_call(char *arg,char name[100][100],char value[100][100],int n);
void sqrt_call(char *arg,char name[100][100],char value[100][100],int n);
#endif
