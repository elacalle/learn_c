#include <stdio.h>

int isLapYear(int year);
int isSameDate(int dateOne[3], int dateTwo[3]);
int daysOfMonth(int m, int year);
char* daysOfWeek(int d);

int main() {
    int fromDate[3] = { 1, 1, 2024 };
    int toDate[3] = { 15, 8, 2030 };
    int sameDay = 0, index = 0, dow = 1;
    
    while(1) {
        int daysOfCurrentMonth = daysOfMonth(fromDate[1], fromDate[2]);

        fromDate[0] = 0;

        do {
            fromDate[0] += 1;
            index++;
            dow = index % 7;

            if(isSameDate(fromDate, toDate)) {
                sameDay = 1;
                break;
            }

        } while (fromDate[0] != daysOfCurrentMonth);

        if(sameDay) { break; } 

        if (fromDate[1] == 12 && fromDate[0] == 31) {
            fromDate[1] = 0;
            fromDate[2] += 1;
        }

        fromDate[1] += 1;
    }

    printf("%d/%d/%d - %s\n", fromDate[0], fromDate[1], fromDate[2], daysOfWeek(dow));
}

int isLapYear(int year) {
    if((year % 100 == 0 && year % 400 == 0 && year % 4 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        return 1;
    }

    return 0;
}

int isSameDate(int dateOne[3], int dateTwo[3]) {
    if((dateOne[0] == dateTwo[0]) && (dateOne[1] == dateTwo[1]) && (dateOne[2] == dateTwo[2])) {
        return 1;
    }

    return 0;
}

int daysOfMonth(int m, int year) {
    switch (m)
    {
    case 1:
        return 31;
    case 2:
        return isLapYear(year) ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}

char* daysOfWeek(int d) {
    char* str;

    switch (d)
    {
    case 0:
        return "Sun";
    case 1:
        return "Mon";
    case 2:
        return "Tue";
    case 3:
        return "Wed";
    case 4:
        return "Thu";
    case 5:
        return "Fri";
    case 6:
        return "Sat";
    }
}
