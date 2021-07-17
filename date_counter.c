#include <stdio.h>

int isleap(int year);
int daysOfMonth(int month, int year);

int main() 
{
	int y1, m1, d1;
  	int y2, m2, d2;
  	int diff = 0;
  	scanf("%d %d %d", &y1, &m1, &d1);
  	scanf("%d %d %d", &y2, &m2, &d2);
  	for (int i = y1; i < y2; i++) {
    		if (isleap(i)) {
      			diff += 366;
    		} else {
      			diff += 365;
    		}
  	}
  	for (int i = 1; i < m1; i++) {
    		diff -= daysOfMonth(i, y1);
  	}
  	diff -= d1;
  	for (int i = 1; i < m2; i++) {
    		diff += daysOfMonth(i, y2);
  	}
  	diff += d2;
  	printf("Days = %d\n", diff);
	printf("Hours = %lu\n", (unsigned long)diff * 24);
	printf("Minutes = %llu\n", (unsigned long long)diff * 1440);
	printf("Seconds = %llu\n", (unsigned long long)diff * 86400);

  	return 0;
}

int isleap(int year) {
  	if (year % 400 == 0) {
    		return 1;
  	} else if (year % 100 == 0) {
    		return 0;
  	} else if (year % 4 == 0) {
    		return 1;
  	} else {
    		return 0;
  	}
}
int daysOfMonth(int month, int year) {
  	switch (month) {
  	case 1:
  	case 3:
	case 5:
  	case 7:
  	case 8:
  	case 10:
  	case 12:
    		return 31;
    		break;
  	case 2:
    		if (isleap(year)) {
      			return 29;
    		} else {
      			return 28;
    		}
    		break;
  	case 4:
  	case 6:
  	case 9:
  	case 11:
    		return 30;
    		break;
  	}
}


