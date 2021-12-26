//msh.c
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <pwd.h>
#include <libgen.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>

char buf[BUFSIZ];
char* myptr;
char* mylim;

char lastdir[100];

void init_lastdir()
{
	getcwd(lastdir, 99);
}

void set_prompt(char* prompt)
{
	char host[100];
	char cwd[100];
	struct passwd* pwp;
	if(gethostname(host, 99) == -1) {
		strcpy(host, "unknown");
	} 
else {
		char* p = strchr(host, '.');
		if(p)
			*p = 0;
	}
	if(!getcwd(cwd, 99)) {
		strcpy(cwd, "unknown");
	} 
else {
		if(strcmp(cwd, "/") != 0)
			strcpy(cwd, basename(cwd));
	}
	pwp = getpwuid(getuid());
	sprintf(prompt, "[%s@%s %s]# ", 
(pwp ? pwp->pw_name : "unknown"), host, cwd);
}
extern void yylex();


void history_setup()
{
	using_history();
	stifle_history(50);
	read_history("/tmp/msh_history");	
}

void history_finish()
{
	append_history(history_length, "/tmp/msh_history");
	history_truncate_file("/tmp/msh_history", history_max_entries);
}

void display_history_list()
{
	HIST_ENTRY** h = history_list();
	if(h) {
		int i = 0;
		while(h[i]) {
			printf("%d: %s\n", i, h[i]->line);
			i++;
		}
	}
}

int main(int argc, char** argv)
{
	char* line;
	char prompt[200];
	
	signal(SIGINT, SIG_IGN);

	init_lastdir();
	history_setup();	

	while(1) {
		set_prompt(prompt);
		if(!(line = readline(prompt))) 
			break;
		if(*line)
			add_history(line);
		strcpy(buf, line);
		strcat(buf, "\n");

		myptr = buf;
		mylim = buf+strlen(buf);
		yylex();
	}
	history_finish();
	return 0;
}
