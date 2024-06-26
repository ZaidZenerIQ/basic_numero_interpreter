#ifndef __VARS_H__
#define __VARS_H__

bool var_checker(char *str_in);
void get_name_var(char *str_in,char *str_out);
void get_value_var(char *str_in,char *str_out);
bool get_type_var(char *str_in);
bool check_use_var(char *str_in,char *var_name);
void see_var(char *str,char name[100][100],char value[100][100],bool *num,int n);
#endif
