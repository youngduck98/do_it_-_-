#include<stdio.h>

typedef struct {
	int y;
	int m;
	int d;
}Date;

Date dateof(int y, int m, int d) {
	Date day;
	day.y = y;
	day.m = m;
	day.d = d;
	return day;
}

Date After(Date x, int n) {
	for (int i = x.m - 1;x.d + n > cal_monthdate(x.y, x.m); i++) {
		n -= cal_monthdate(x.y, x.m);
		if(x.m>12){
			x.y++;
			x.m -= 12;
		}
		else {
			x.m++;
		}
	}
	x.d += n;
	return x;
}

int find_all_day(Date a, Date b) {
	Date c;
	//a를 다음년도 1월 1일까지 필요한 날 수를 구하고
	int sum1 = 0;
	for (int i = a.m; i <= 12; i++) {
		sum1 += cal_monthdate(a.y, i);
		printf("sum1: %d\n", sum1);
	}
	sum1 -= a.d;
	printf("\n%d\n", sum1);
	//해당 년도에서 b의 1월 1일 까지의 차이를 구하고
	int sum2 = 0;
	for (int y = a.y + 1; y < b.y; y++) {
		for (int m = 1; m <= 12; m++) {
			sum2 += cal_monthdate(y, m);
		}
	}
	printf("%d\n", sum2);
	//해당 년에서 지난 날을 구함
	int sum3 = 0;
	for (int m = 1; m < b.m; m++) {
		sum3 += cal_monthdate(b.y, m);
	}
	sum3 += b.d;
	printf("%d\n", sum3);
	return sum1 + sum2 + sum3;
}

int cal_monthdate(int year, int month) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	}
	if(year%4 == 0){
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 29;
			}
			else {
				return 28;
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

int main() {
	Date day;
	day.d = 3;
	day.m = 11;
	day.y = 1970;
	Date today;
	today.d = 29;
	today.m = 1;
	today.y = 2022;
	printf("%d %d %d", day.y, day.m, day.d);
	printf("\nday: %d", find_all_day(day, today));
}