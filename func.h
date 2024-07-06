#ifndef __FUNC_H__
#define __FUNC_H__
void built_in_func(char func_name[100][100]);
bool check_func(char *str,char func_name[100][100],char *func);
void function_call(char *func,char *arg);
int get_arg(char *str,char *arg);
void out_call(char *arg);
#endif
