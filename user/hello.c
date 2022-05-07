#include "kernel/types.h"
#include "kernel/stat.h"

#include "user/user.h"

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);

    for (int i = 0; i < num; i++) printf("Hello muduck! x%d \n", i);
    
    exit(0);
}