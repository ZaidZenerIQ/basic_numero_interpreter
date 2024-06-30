#ifndef __VARS_H__
#define __VARS_H__

bool var_checker(char *str_in);
void get_name_var(char *str_in,char *str_out);
void get_value_var(char *str_in,char *str_out);
bool get_type_var(char *str_in);
bool use_var(char *str);
void pars_var(char *str,char *equ,char array_str[100][100],int *j);
void get_tok(bool *arr,char str[100][100],int c);
void get_vals(char streq[100][100],char name[100][100],char value[100][100],bool *tok,int c,int n);
void make_equ(char *str,char strq[100][100],char *equ,int c);
#endif
