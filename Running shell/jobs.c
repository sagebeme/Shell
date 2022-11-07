#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"

Job *first_job = NULL;

Job *make_job(unsigned jid,pid_t pid, char *cmdline)
{
    Job *job = malloc(sizeof(job));

    if (!job)
    {
        fprintf(stderr, "  Unable to allocate memory for new job ");
        return NULL;
    }
    job ->jid =jid;
    job ->pid =pid;
    job ->stopped = 0;
    job ->last = NULL;
    job ->next = NULL;
    strcpy(job-> cmdline, cmdline);

    if (!first_job)
    {
        first_job = job;
        return (job);
    }
    /* add to lists of jobs*/
    Job *job = first_job;
    while (j -> next)
    {
        j = j -> next;
    }
        j -> next = job;
        job ->last = j;

        return (job);
}
void remove_last_job(Job *j)
{
    Job j;
    for (j = first_job; j; j = j->next)
    {
        if (j->pid == job->pid)
        {
            if (!j->last && !j->next)
            {
                first_job = NULL;
            }
            else
            {
                if(!j->last &&!j->next)
                {
                    first_job = NULL;
                }else
                {
                    j->last->next = j ->next;
                }
                if (j-> next)
                {
                    j->last->next = j ->next;
                }
                free(job);
                return;
            }
        }
        fprintf(stderr," Job %d not in bg job list\n",job->pid);
    }
}

Job *job_with_pid(unsigned pid)
{
    Job *j;
    for (j = first_job; j; j = j->next)
    {
        if (j ->jid == jid)
        {
            return(j);
        }
    }
    return NULL;
}

Job *job_with_pid(pid_t pid)
{
    Job *j;
    for (j = first_job; j; j = j->next)
    {
        if (j ->jid == jid)
        {
            return(j);
        }
    }
    return NULL;
}

int mark_process_status(pid_t pid, int status)
{
    Job *j;

    if (pid >0)
    {
        /* update the record of the process.  */
        for (j= first_job; j; j= j ->jid)
        {
            if (j->pid ==pid)
            {
                printf(" [%d] %d %s",j->jid, j->pid,j->cmdline);
               if (WAITIFSTOPPED(status))
               {
                printf("job %d stopped\n",pid);
                j-> stopped =1;
                }
                else if (WIFEXITED(status))
                {
                    printf("job %d exited normally\n",pid);
                    remove_job(j);
                }
                else if (WIFSIGNALED(status))
                {
                    printf("job %d terminated by signal %d\n",pid,WSIGTERM(status));
                    remove_job(j);
                }
                }
                
                
                return (0);
            }
        }
        fprintf(stderr,"No child process %d\n",pid);
        return(-1);
    }
    else if (pid == 0 || errno == ECHILD)
    {
        /* No process ready to report */
        return -1;
    }
    else
    {
        /*other wierd errors*/
        perror("waitpid");
        return(-1);
    }
}

void update_jobs()
{
    pid_t pid;
    int status;
}