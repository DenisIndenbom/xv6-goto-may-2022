#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define PERENT_MSG "pong"
#define CHILD_MSG "ping"

int main(int argc, char *argv[])
{
    int perent_p[2], child_p[2];

    char buf[10];

    int i = 0;
    
    pipe(perent_p); // init file descryprot for perent
    pipe(child_p); // init file descryprot for child
    
    int child_pid = fork(); // create child process

    if(child_pid < 0)
    {
        printf("error\n");
        exit(0);
    }
    else if(child_pid == 0)
    {
        while (i < atoi(argv[1]))
        {
            int nbytes = read(child_p[0], buf, sizeof(buf));

            if (nbytes > 0) 
            {
                printf("%d: received %s\n", getpid(), buf);
                write(perent_p[1], PERENT_MSG, sizeof(PERENT_MSG));

                i++;
            }
        }

        close(child_p[0]);
        close(child_p[1]);
        exit(0);
    }
    else
    {
        write(perent_p[1], PERENT_MSG, sizeof(PERENT_MSG));

        while (i < atoi(argv[1]))
        {
            int nbytes = read(perent_p[0], buf, sizeof(buf));

            if (nbytes > 0) 
            {
                printf("%d: received %s\n", getpid(), buf);
                write(child_p[1], CHILD_MSG, sizeof(CHILD_MSG));

                i++;
            }
        }

        close(perent_p[0]);
        close(perent_p[1]);
    }
    exit(0);
}