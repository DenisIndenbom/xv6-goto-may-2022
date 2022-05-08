#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

int main()
{
    struct sysinfo info;

    sysinfo(&info);

    printf("Free memory: %d \n", info.freemem);
    printf("Process: %d \n", info.nproc);

    exit(0);

    return 0;
};