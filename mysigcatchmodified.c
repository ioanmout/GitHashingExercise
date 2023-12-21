#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal Counter
int sigint_count = 0;

// Signal Handler Function for SIGINT signal
void custom_sigint_handler(int signum) {
    printf("Caught SIGINT signal (%d)\n", signum);

    // Increment the counter
    sigint_count++;

    // Check if SIGINT has been caught twice
    if (sigint_count == 2) {
        // Restore the default behavior for SIGINT
        signal(SIGINT, SIG_DFL);
        printf("SIGINT was caught twice. Restoring default behavior.\n");
        sigint_count = 0;
    }
}

int main() {
    // Register the custom signal handler for SIGINT
    if (signal(SIGINT, custom_sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Unable to register SIGINT handler\n");
        return 1;
    }

    printf("Press Ctrl+C to send a SIGINT signal...\n");

    while (1) {
    }

    return 0;
}