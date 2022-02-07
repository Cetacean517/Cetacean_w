#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>

char command_str[256];
char param_list[20][256];
int ReadCommand(void);
int ParseCommand(void);
int ExcuteCommand(void);
int mypwd(void);
int mycd(void);
int mydir(void);
 
int ReadCommand(void)
// 读入指令,存入 command_str数组，以0结尾
{
    char c;
    int i=0;
    while (scanf("%c",&c)!=EOF && c!='\n' && i<256)
    {
        command_str[i]=c;
        i++;
    }
    command_str[i]=0;   //最后一个指令置0
    return 0;
}
 
int ParseCommand(void)
// 语义分析
{
    unsigned int i=0,j=0,n=0;
    int blank_flag=1;
    for (i=0;i<strlen(command_str);i++)
    {
        if (command_str[i]==' '|| command_str[i]=='\t')
        {
            if (blank_flag==0)
            {
                param_list[n][j]=0;
                n++;
                j=0;
                blank_flag=1;
            }
        }
        else{
            param_list[n][j]=command_str[i];
            j++;
            blank_flag=0;
            } 
    }
    if (blank_flag==1){
        param_list[n][0]=0;
        }
    else{
        param_list[n][j]=0;
        n++;
        param_list[n][0]=0;
        }
    return 1;
}
int ExcuteCommand(void)
// 执行指令
{
    if (strcmp("dir",param_list[0])==0) // dir指令
    {
        mydir();
        return 0;
    }
    if (strcmp("pwd",param_list[0])==0) // pwd指令
    {
        mypwd();
        return 0;
    }
    if (strcmp("cd",param_list[0])==0) // cd指令
    {
        mycd();
        return 0;
    }

    if(strcmp("exit",param_list[0])==0)
    {
        exit(0);
    } 
}

// 自定义指令的功能
int mypwd(void)
{
    char buf[256];
    getcwd(buf,sizeof(buf));
    printf("%s\n",buf);
    return 0;
}

int mycd(void)
{
    if (strcmp("",param_list[1])==0)
        return -1;

    if (chdir(param_list[1])==-1)
    {
        printf("目录不存在!\n");
        return -1;
    }
    return 0;
}
 
int mydir(void)
{
    DIR* dirp;
    struct dirent * ent;
    if (strcmp("",param_list[1])==0)
        dirp=opendir(".");
    else
        dirp=opendir(param_list[1]);
    if (dirp==NULL)
    {
        printf("打开目录失败!\n");
        return -1;
    }
    while ((ent=readdir(dirp))!=NULL)
    {
        if (ent->d_name[0]!='.')
        printf("%s\t",ent->d_name);
    }
        printf("\n");
        closedir(dirp);
    return 0;
}

int main(int argc,char*argv[])
{   
    printf("————————Welcome————————————\n");  
    while (1)
    {
        printf("[root@localhost]$");
        ReadCommand();
        ParseCommand();
        if (ExcuteCommand()==-1)
            break;
    }
    return 0;
}