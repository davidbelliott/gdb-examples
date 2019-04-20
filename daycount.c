#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_BASE 10

#define TRUE 1
#define FALSE 0

const int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
const int FEB_DAYS_LEAP = 29;

typedef struct date_t {
    int year;
    int month;
} date_t;

typedef struct date_array_t {
    date_t *dates;
    int count;
} date_array_t;

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

int get_n_days(int year, int month) {
    int leap = is_leap_year(year);
    int n_days;
    if (month != 2) {
        n_days = MONTH_DAYS[month];
    } else {
        n_days = (leap = TRUE ? FEB_DAYS_LEAP : MONTH_DAYS[month]);
    }
    return n_days;
}

void load_dates(FILE *input, date_array_t *dates) {
    int count;
    if (fscanf(input, "%d", &count) != 1) {
        fprintf(stderr, "error:  couldn't read count from input list\n");
        exit(1);
    }

    if (count <= 0) {
        fprintf(stderr, "error: count must be positive; got %d\n", count);
        exit(1);
    }

    float *values = malloc(count * sizeof(float));
    if (values == NULL) {
        printf("ERROR:  couldn't allocate %u bytes!\n",
               (unsigned int) (count * sizeof(float)));
        exit(1);
    }

    /* Zero out the newly allocated memory. */
    memset(values, 0, count * sizeof(float));

    /* Load each floating-point value into its corresponding location
     * in the array.
     */
    for (i = 0; i < count; i++) {
        if (fscanf(input, "%f", &value) != 1) {
            printf("ERROR:  couldn't read a value from input list\n");
            exit(1);
        }

        values[i] = value;
    }

    /* Finally, store the loaded values into the passed-in struct. */
    floats->count = count;
    floats->values = values;
}

void usage(const char* progname) {
    fprintf(stderr, "usage: %s year month\n", progname);
    fprintf(stderr, "\tyear: the year (all 4 digits)\n");
    fprintf(stderr, "\tmonth: the month (1-12)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
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
    int month = strtol(argv[2], &ptr, NUMBER_BASE);
    if (ptr != argv[2] + strlen(argv[2])) {
        fprintf(stderr, "error: %s not a valid month\n", argv[2]);
        usage(argv[0]);
        return 1;
    }
    int n_days = get_n_days(year, month);
    printf("%d\n", n_days);
    return 0;
}
