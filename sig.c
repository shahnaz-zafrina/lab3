#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int signo)
{
    if (signo == SIGINT)
       printf("This is a special signal handler for SIGINT\n");
    else if (signo == SIGSTP)
        printf("This is special signal handler for SIGSTP\n");
    else if (signo == SIGQUIT)
        printf("This is a special signal handler for SIGQUIT\n");
}
int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGNINT\n");
    if (signal(SIGSTP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTP\n");
    if (signal(SIGQUIT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGQUIT\n");
    // A long long wait so that we can easily issue a signal to this process
    while(1) 
        sleep(1);
    return 0;
}
