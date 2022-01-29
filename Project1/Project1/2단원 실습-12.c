#include<stdio.h>

int make_month_day(int year, int month) {
	if (month == 2) {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					return 28;
				}
				else {
					return 29;
				}
			}
			else {
				return 29;
			}
		}
		else {
			return 28;
		}
	}
	else if (month % 2 == 0) {
		return 30;
	}
	else {
		return 31;
	}
}



int main() {
	int year, month, day;
	int sumdays = 0;
	printf("year month day");
	scanf("%d %d %d", &year, &month, &day);

	int month_days[12];
	for (int i = 0; i < 12; i++) {
		*(month_days + i) = make_month_day(year, i);
	}

	for (int i = 0; i < month-1; i++) {
		sumdays += *(month_days + i);
	}
	sumdays += day;

	printf("%d", sumdays);
}