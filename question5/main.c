#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int is_leap(int year);
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
void test_day_of_year();
void test_month_day();

int is_leap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap = is_leap(year);

  // Range check.
  if (year < 0 || month < 1 || month > 12 || day < 1 ||
      day > daytab[leap][month])
    return -1;

  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }

  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap = is_leap(year);

  // Range check.
  if (year < 0 || yearday < 1 || yearday > 365 + leap) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }

  *pmonth = i;
  *pday = yearday;
}

void test_day_of_year() {
  int test_data[3][3] = {{1998, 3, 27}, {-2, 10, 10}, {10, 13, 2}};

  int i;
  for (i = 0; i < 3; i++) {
    printf("day_of_year(%d, %d, %d) = %d\n", test_data[i][0], test_data[i][1],
           test_data[i][2],
           day_of_year(test_data[i][0], test_data[i][1], test_data[i][2]));
  }
}

void test_month_day() {
  int test_data[3][2] = {{1998, 172}, {-1, 13}, {2012, 366}};

  int i;
  for (i = 0; i < 3; i++) {
    int m, d;
    month_day(test_data[i][0], test_data[i][1], &m, &d);
    printf("Day %d of year %d is ", test_data[i][1], test_data[i][0]);
    if (d == -1)
      printf("invalid input\n");
    else
      printf("%d/%d\n", m, d);
  }
}

int main() {
  test_day_of_year();
  test_month_day();
  return 0;
}
