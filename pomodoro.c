#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WORK_MIN 25
#define SHORT_PAUSE_MIN 5
#define LONG_PAUSE_MIN 15
#define SEC_IN_MIN 60
#define WORK_CYCLES 4

void sleep_min(unsigned int);
int print_timer(unsigned int);

int main(void) {
    int cycle = 1;

    while (true) {
        printf("Start to work!\n...");
        print_timer(WORK_MIN);
        if (cycle % WORK_CYCLES != 0) {
            system("notify-send Pomodoro \"Time for a short pause!\"");
            printf("Short pause!\n");
            print_timer(SHORT_PAUSE_MIN);
            cycle++;
        } else {
            system("notify-send Pomodoro \"Time for a long pause!\"");
            printf("Long pause!\n");
            print_timer(LONG_PAUSE_MIN);
            cycle++;
        }
    }

    return 0; 
}

void sleep_min(unsigned int min) {
    sleep(min * SEC_IN_MIN);
}

int print_timer(unsigned int total_minutes) {
    if (total_minutes >= 60) {
        printf("Provide a time interval (in minutes) < 1 hour\n");
        return 1;
    }

    int total_seconds = total_minutes * SEC_IN_MIN;
    
    while (total_seconds >= 0) {
        int shown_min = total_seconds / SEC_IN_MIN;
        int shown_sec = total_seconds % SEC_IN_MIN; 
        printf("\r%.2u:%.2u", shown_min, shown_sec);
        fflush(stdout);
        sleep(1);
        total_seconds--;
    }
    printf("\n");
    return 0;
}