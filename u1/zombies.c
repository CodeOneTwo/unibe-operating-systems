/* gcc -Wall -std=gnu99 zombies.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_zombie() {
    if (fork() == 0) {
        exit(0);
    } else {
        printf("hello from parent process ;-)\n");
    }
    return;
}

int main(void)
{
    int wait = 15;
    create_zombie();
    sleep(wait);

    /* optionally wait for child process to end the misery of zombie process */
    return 0;
}
