#include "kernel/types.h"
#include "kernel/stat.h"

#include "user/user.h"


int main(int argc, char *argv[])
{
    printf("I go to sleep!\n");
    
    sleep(atoi(argv[1]));

    printf("I am wake up!\n");

    exit(0);
}