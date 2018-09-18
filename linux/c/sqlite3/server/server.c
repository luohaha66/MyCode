#include "server.h"

int flag = 1;
char hhh[1024] = {0};
char aaa[1024] = {0};
char name[20] = {0};

void register_new_user(int fd, char* name)
{
	char c = 'a';
	char b = 'e';
	int i = 0;
	sqlite3* db = NULL;
	int nrow = 0;
	int ncolumn = 0;
	char** result = NULL;
	char pass[20] = {0};
	char sql[128] = {0};
	char his[5] = {"aa"};
	char* errmsg = NULL;
	if(sqlite3_open("./user.db", &db) != SQLITE_OK)
		{
			printf("open database error:%s\n", sqlite3_errmsg(db));
			exit(EXIT_FAILURE);
		}
	read(fd, name, 20);
	read(fd, pass, 20);
	i = strlen(name);
	name[i - 1] = '\0';
	i = strlen(pass);
	pass[i - 1] = '\0';
	sprintf(sql, "select * from info where user='%s';", name);
	if (sqlite3_get_table(db, sql, &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
		{
			printf("sql error:%s\n", errmsg);
			exit(EXIT_FAILURE);
		}
	if(nrow != 0)
		{
			write(fd, &b, 1);
			sqlite3_close(db);
			return;
		}
	memset(sql, 0, 128);
	sprintf(sql, "insert into info values('%s', '%s', '%s');", name, pass, his);
	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
		{
			printf("sql error:%s\n", errmsg);
			exit(EXIT_FAILURE);
		}
	write(fd, &c, 1);
	flag = 0;
	sqlite3_close(db);
}

void user_login(int fd, char* name)
{
	char c = 'b';
	char b = 'f';
	int i = 0;
	int nrow = 0;
  int ncolumn = 0;
  char** result = NULL;
	char* errmsg = NULL;
	char sql[128] = {0};
	char pass[20] = {0};
	sqlite3* db = NULL;
	if(sqlite3_open("./user.db", &db) != SQLITE_OK)
		{
			printf("open database error:%s\n", sqlite3_errmsg(db));
			exit(EXIT_FAILURE);
		}
	read(fd, name, 20);
	read(fd, pass, 20);
	i = strlen(name);
	name[i - 1] = '\0';
	i = strlen(pass);
	pass[i - 1] = '\0';
	sprintf(sql, "select * from info where user='%s' and passwd='%s';", name, pass);
	if (sqlite3_get_table(db, sql, &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
		{
			printf("sql error:%s\n", errmsg);
			exit(EXIT_FAILURE);
		}
	if(nrow != 0)
		{
			write(fd, &c, 1);
		}
	else
		{
			write(fd, &b, 1);
			sqlite3_close(db);
			return;
		}
	flag = 0;
	sqlite3_close(db);
}

void handler(int fd, char* name)
{
	while(flag)
	{
		char cmd;
  	read(fd, &cmd, 1);
  	memset(name, 0, sizeof(name));
  	if (cmd == 'y')
  		register_new_user(fd, name);
  	if (cmd == 'n')
  		user_login(fd, name);
	}
}

int callback(void* para, int num, char** f_value, char** f_name)
{
	int i = 0;
	for(i = 0; i < num; i++)
	{
		if(i == 2)
			{
				memset(hhh, 0, 1024);
				if (strcmp(f_value[i], "aa") != 0) 
					strcat(hhh, f_value[i]);
			}
	}
	return 0;
}

int callback1(void* para, int num, char** f_value, char** f_name)
{
	int i = 0;
	for(i = 0; i < num; i++)
	{
		if(i == 2 && f_value[i] != NULL)
				strcat(aaa, f_value[i]);
	}
	return 0;
}

void history_add(int clifd, char* name, char* word)
{
	sqlite3* db = NULL;
	char* errmsg = NULL;
  int i = 0;
	char sql[128] = {0};
	if(sqlite3_open("./user.db", &db) != SQLITE_OK)
		{
			printf("open database error:%s\n", sqlite3_errmsg(db));
			exit(EXIT_FAILURE);
		}
	sprintf(sql, "select * from info where user='%s';", name);
	if (sqlite3_exec(db, sql, callback, NULL, &errmsg) != SQLITE_OK) 
  	{
  		printf("sqlite3_exec error: %s\n", errmsg);
  		exit(EXIT_FAILURE);
  	}
  memset(sql, 0, 128);
  if(strstr(hhh, word) == NULL)
  	{
  		strcat(word, " ");
      strcat(hhh, word);
    	sprintf(sql, "update info set history='%s' where user='%s';", hhh, name);
    	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) 
      	{
      		printf("sqlite3_exec error: %s\n", errmsg);
      		exit(EXIT_FAILURE);
      	}
  	}
  sqlite3_close(db);
}

void get_history(char* name)
{
	sqlite3* db = NULL;
	char* errmsg = NULL;
  int i = 0;
	char sql[128] = {0};
	if(sqlite3_open("./user.db", &db) != SQLITE_OK)
		{
			printf("open database error:%s\n", sqlite3_errmsg(db));
			exit(EXIT_FAILURE);
		}
	sprintf(sql, "select * from info where user='%s';", name);
	if (sqlite3_exec(db, sql, callback1, NULL, &errmsg) != SQLITE_OK) 
  	{
  		printf("sqlite3_exec error: %s\n", errmsg);
  		exit(EXIT_FAILURE);
  	}
  sqlite3_close(db);
}

void find_word(int clifd, char* name)
{
	char buf[512] = {0};
	char wor[20] = {0};
	char data[20] = {0};
	char tmp[20] = {0};
	char c;
	int i = 0;
	while(1)
	{
LOOP:
		memset(buf, 0, 512);
  	memset(wor, 0, 512);
  	memset(data, 0, 20);
  	memset(tmp, 0, 20);
  	FILE* fp = NULL;
  	if ((fp = fopen("./dict.txt", "r")) == NULL)
  		{
  			perror("fopen error:");
  			exit(EXIT_FAILURE);
  		}
  	if (read(clifd, data, 20) != 0)
  		{
  			i = strlen(data);
  	    data[i - 1] = '\0';
  	    strcpy(tmp, data);
  		}
  	if (strcmp(data, "q") == 0)
  		{
  			close(clifd);
  			exit(EXIT_SUCCESS);
  		}
  	if(strcmp(data, "h") == 0)
  		{
  			get_history(name);
  			write(clifd, aaa, strlen(aaa));
  			memset(aaa, 0, 1024);
  			goto LOOP;
  		}
  	while(1)
  	{
  		memset(buf, 0, 512);
  		memset(wor, 0, 20);
  		fgets(buf, 512, fp);
  		sscanf(buf, "%[^ ]", wor);
  		if(strcmp(tmp, wor) == 0)
  			break;
  		if(feof(fp))
  			{
  				c = 's';
  				write(clifd, &c, 1);
  				goto LOOP;
  			}
  	}
  	history_add(clifd, name, tmp);
  	c = 'b';
  	write(clifd, &c, 1);
  	write(clifd, buf, strlen(buf));
	}
}

void hand()
{
	while(waitpid(-1, NULL, WNOHANG));
}

void run(int arg)
{
	memset(name, 0, 20);
	handler(arg, name);
	find_word(arg, name);
}