#ifndef _CLIENT_H_
#define _CLIENT_H_

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

void download(char* name, int clifd);
void upload(char* name, int clifd);
void handle(char* buf, char* cmd, int clifd);

#endif