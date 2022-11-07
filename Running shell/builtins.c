#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "csapp.h"
#include "builtins.h"

/* if first argument is a bult in command run it and return true*/
int builtin_command(int argc, char **argv)
{
    if (!strcmp(argv[0],"quit"))
        exit(0);
    if (!strcmp(argv[0],"&"))
        return(1);
    if (!strcmp(argv[0],"jobs"))
        return command_jobs(argc,argv);
    if (!strcmp(argv[0],"bg"))
        return command_bg(argc,argv);
    if (!strcmp(argv[0],"fg"))
        return command_fg(argc,argv);
    return 0;

    int command_jobs(int argc, char **argv)
    {
        pid_t pid;
        int status;
        Job *j;
        for (j-> first_job; j; j= j->next)
        {
            printf("[%d] %d %s  %s",
            j->jid,
            j->pid,
            j-> stopped? "stopped" : "running",
            j ->cmdline);
            return (1);
        }
    }
    int command_bg(int argc, char **argv)
    {
        if (argc > 2)
        {
            printf("Usage: bg <job>\n");
            printf("    job can either be a process id or job id prefix with %%\n");
            printf("examples: \n");
            printf("    bg 12345 - runs job with process id 12345 in the backgroung \n");
            printf("    bg %%5 - runs job with process id 5 in the backgroung \n");

            return 1;
        }
        Job *j;
        if (arg[1][0] ==%)
        {
            unsigned jid = atoi(argv[1]+1);
            j = job_with_jid(jid);
        }else{
            pid_t pid = atoi(argv[1]);
        }
        if (!j)
        {
            fprintf(stderr,"NO job with specified jid or pid \n");
            return(1);
        }
        kill(-j ->pid ,SIGCOUNT);
        j -> stopped = 0;

        return 1;

    }
    int command_fg(int argc, char **argv)
    {
        if (argc > 2)
        {
            printf("Usage: bg <job>\n");
            printf("    job can either be a process id or job id prefix with %%\n");
            printf("examples: \n");
            printf("    bg 12345 - runs job with process id 12345 in the backgroung \n");
            printf("    bg %%5 - runs job with process id 5 in the backgroung \n");

            return 1;
        }
        Job *j;
        if (arg[1][0] ==%)
        {
            unsigned jid = atoi(argv[1]+1);
            j = job_with_jid(jid);
        }else{
            pid_t pid = atoi(argv[1]);
        }
        if (!j)
        {
            fprintf(stderr,"NO job with specified jid or pid \n");
            return(1);
        }
        kill(-j ->pid ,SIGCOUNT);
        j -> stopped = 0;

        /*Mark job as needing to continue in foreground*/

        return 1;

    }
}