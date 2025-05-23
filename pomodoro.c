#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define WORK_MIN 25
#define SHORT_PAUSE_MIN 5
#define LONG_PAUSE_MIN 15
#define SEC_IN_MIN 60
#define WORK_CYCLES 4

void sleep_min(unsigned int);

int main(void) {
    int cycle = 1;

    while (true) {
        printf("Start to work!\n...");
        sleep_min(WORK_MIN);
        if (cycle % WORK_CYCLES != 0) {
            printf("Short pause!\n");
            sleep_min(SHORT_PAUSE_MIN);
            cycle++;
        } else {
            printf("Long pause!\n");
            sleep_min(LONG_PAUSE_MIN);
            cycle++;
        }
    }

    return 0; 
}

void sleep_min(unsigned int min) {
    sleep(min * SEC_IN_MIN);
}