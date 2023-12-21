#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal Handler Function for SIGINT signal
void sigint_handler(int signum) {
    printf("\nSIGINT signal caught!\n");

    // Terminate the program
    exit(signum);  
}

int main() {
    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Unable to register SIGINT handler\n");
        return 1;
    }

    printf("Press Ctrl+C to send a SIGINT signal...\n");

    while (1) {
    }

    return 0;
}