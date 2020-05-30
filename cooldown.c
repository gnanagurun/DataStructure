#if 0

 Question:

 Given a list of input tasks to run, and the cooldown interval, output the task with cooldown

 Input tasks: A, A, B, A
 cooldown: 2
 Output: A, _, _, A, B, _, A

 Input tasks: A, A, B, A, B
 cooldown: 2
 Output: A _ _ A B _ A B ) 

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SEQ 10

void print_job(char *job, int cooldown)
{
    char job_seq[26];
    int cnt = 0, i, diff;
    memset(job_seq, -1, sizeof(job_seq));
    for (i=0; job[i]; i++)
    {
	if(job_seq[job[i]-'A'] == -1)
	{
	    printf("%c%c",i==0?'\0':',',job[i]);
	    cnt++;
	}
	else
	{
	    diff = (cnt+1) - job_seq[job[i] - 'A'];
	    if(diff > cooldown)
	    {
		printf(",%c",job[i]);
		cnt++;
	    }
	    else
	    {
		while(diff <= cooldown)
		{
		    printf(",_");
		    cnt++, diff++;
		}
		printf(",%c",job[i]);
	    }
	}
	job_seq[job[i]-'A'] = cnt;
    }
    printf("\n");
}

int main()
{
    char seq[MAX_SEQ+1];
    int cooldown;
    printf("Enter the job sequence(string) and cooldown(int):");
    scanf("%s %d",seq, &cooldown);
    print_job(seq, cooldown);
    return 0;
}
