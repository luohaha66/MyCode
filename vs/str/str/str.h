#pragma once
#ifndef _STR_H_
#define _STR_H_

char* my_strcpy(char* s, char* p);
int my_strlen(char* s);
int my_strcmp(char* s, char* p);
char* my_strcat(char* s, char* p);
char* my_strins(char* s, char* t, int m);
char* my_strdel(char* s, char* q);
int continumax(char *outputstr,char *inputstr);
long my_atol(const char* nptr);
char *delstr(char *p);
char* exchange(char* p);
char *my_strstr(char *p, char *q);
int *changepos(int *a, int m;
char* my_itoa(int m,char* s);
int trans1(char *a,int d1);
void trans2(unsigned long n, int d, char *s);

#endif // !_STR_H_
