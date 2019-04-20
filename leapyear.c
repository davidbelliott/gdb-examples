#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_BASE 10

#define TRUE 1
#define FALSE 0

int is_leap_year(int year) {
    if (year % 4) {    // not divisible by 4 -> not a leap year
        return FALSE;
    }
    if (year % 100) {   // divisible by 4 but not 100 -> leap year
        return TRUE;
    }
    if (!(year % 400)) {   // year is evenly divisible by 400
        return TRUE;
    }
    return FALSE;
}

void usage(const char* progname) {
    fprintf(stderr, "usage: %s year\n", progname);
    fprintf(stderr, "\tyear: the year (YYYY)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    char *ptr;
    int year = strtol(argv[1], &ptr, NUMBER_BASE);
    if (ptr != argv[1] + strlen(argv[1])) {
        fprintf(stderr, "error: %s not a valid year\n", argv[1]);
        usage(argv[0]);
        return 1;
    }
    int leap = is_leap_year(year);
    printf("%d: %d\n", year, leap);
    return 0;
}
