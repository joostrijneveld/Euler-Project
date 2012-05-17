#include <iostream>

using namespace std;

int is_leapyear(int y) {
	if (y % 4 == 0 && y % 400 != 0) {
		return 1;
	}
	return 0;
}

int days_in_month(int m, int leap) {
	switch (m) {
		case 9 :
		case 4 :
		case 6 :
		case 11:
			return 30;
			break;
		case 2 :
			return 28+leap;
			break;
		default:
			return 31;
			break;
	}
}

int day_of_week(int d, int m, int y) {
	int days_since_0 = 0;
	int currleap = is_leapyear(y);
	while (y > 1900) {
		y--;
		days_since_0 += 365 + is_leapyear(y);
	}
	while (m > 1) {
		m--;
		days_since_0 += days_in_month(m,currleap);
	}
	days_since_0 += d - 1;
	return days_since_0 % 7;
}

int main() {
	int month = 1, year = 1900;
	int sundays = 0;
	while (month != 1 || year != 2001) {
		if (day_of_week(1,month,year) == 6) {
			sundays++;
		}
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
	cout << sundays;
	return 0;
}
