#include<sys/stat.h>
#include<sys/types.h>
#include<sys/sysmacros.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#define TIME_STRING_LEN 50
char *time2String(time_t tm,char *buf)
{ struct tm *local;
local=localtime(&tm);
strftime(buf,TIME_STRING_LEN,"%c",local);
return buf;
}
int ShowFileInfo(char *file)
{ struct stat buf;
 char timeBuf[TIME_STRING_LEN];
if(lstat(file,&buf))
{ perror("lstat() error");
return 1;
}
printf("\nFile:%s\n",file);
printf("On device(major/minor):%d %d,inode number:%ld\n",
major(buf.st_dev),minor(buf.st_dev),buf.st_ino);
printf("Size:%ld\t Type: %07o\t Permission:%05o\n",buf.st_size,buf.st_mode & S_IFMT,buf.st_mode & ~(S_IFMT));
printf("Ower id:%d\t Group id:%d\t Number of hard links:%d\n", buf.st_uid,buf.st_gid,buf.st_nlink);
printf("Last access:%s\n",time2String(buf.st_atime,timeBuf));
printf("Last modify inode:%s\n\n",time2String(buf.st_atime,timeBuf));
return 0;
}
int main(int argc,char *argv[])
{ int i,ret;
for(i=1;i<argc;i++)
{ ret=ShowFileInfo(argv[i]);
if(argc-i>1) printf("\n");
}
return ret;
}
