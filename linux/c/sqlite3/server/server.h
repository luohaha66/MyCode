#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sqlite3.h>
#include <sys/wait.h>
#include <signal.h>

void register_new_user(int fd, char* name);
void user_login(int fd, char* name);
void handler(int fd, char* name);
void find_word(int clifd, char* name);
void history_add(int clifd, char* name, char* word);
int callback(void* para, int num, char** f_value, char** f_name);
int callback1(void* para, int num, char** f_value, char** f_name);
void get_history(char* name);
void run(int arg);
void hand();

#endif