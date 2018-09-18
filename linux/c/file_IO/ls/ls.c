#include "ls.h"

void my_lsfile(char* s)
{
	DIR* d = opendir(s);
	struct dirent *p = NULL;
	while (( p = readdir(d)) != NULL)
	{
		if (p->d_name[0] == '.')
			continue;
		printf("%s ",p->d_name);
	}
	printf("\n");
	close(d);
}

void my_opendir(char* s)
{
	DIR* d = opendir(s);
	struct dirent *p = NULL;
	while (( p = readdir(d)) != NULL)
	{
		if (p->d_name[0] == '.')
			continue;
		get_file_info(p->d_name);	
	}
	close(d);
}

void get_file_info(char* q)
{
	struct stat info;
	char buf[11] = {"----------"};
	if (lstat(q, &info) == -1)
		{
			printf("Get Infomation Error\n");
			return;
		}
	switch(info.st_mode & S_IFMT)
    {
        case S_IFSOCK:
            buf[0] = 's';
            break;
        case S_IFREG:
            buf[0] = '-';
            break;
        case S_IFBLK:
            buf[0] = 'b';
            break;
        case S_IFDIR:
            buf[0] = 'd';
            break;
        case S_IFIFO:
            buf[0] = 'p';
            break;
        case S_IFCHR:
            buf[0] = 'c';
            break;
        default:
            buf[0] = 'l';
            break;
    }
    if ( info.st_mode & S_IRUSR )
    {
        buf[1] = 'r';
    }
    if ( info.st_mode & S_IWUSR )
    {
        buf[2] = 'w';
    }
    if ( info.st_mode & S_IXUSR )
    {
        buf[3] = 'x';
    }
    if ( info.st_mode & S_IRGRP )
    {
        buf[4] = 'r';
    }
    if ( info.st_mode & S_IWGRP )
    {
        buf[5] = 'w';
    }
    if ( info.st_mode & S_IXGRP )
    {
        buf[6] = 'x';
    }
    if ( info.st_mode & S_IROTH )
    {
        buf[7] = 'r';
    }
    if ( info.st_mode & S_IWOTH )
    {
        buf[8] = 'w';
    }
    if ( info.st_mode & S_IXOTH )
    {
        buf[9] = 'x';
    }
    
    struct passwd *p = getpwuid(info.st_uid);
    struct group *g = getgrgid(info.st_gid);
    struct tm *t = NULL;
    t = localtime( &(info.st_mtime));
    printf("%s %d %s %s %d %d-%d-%d,%d:%d %s\n", buf, (int)info.st_nlink, p->pw_name, g->gr_name,
    (int)info.st_size, t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, q);
}




