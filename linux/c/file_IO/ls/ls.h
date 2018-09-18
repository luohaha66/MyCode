#ifndef _LS_H_
#define _LS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void my_lsfile(char* s);
void my_opendir(char* s);
void get_file_info(char* q);


#endif