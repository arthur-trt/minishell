#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("Caught SIGINT\n");
	exit(signo);
}

int main(void)
{

	printf("lol\n");
	signal(SIGINT, sigint_handler);

}