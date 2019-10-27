#include <iostream>
#include <utility>
using namespace std;

int hour, minute, cookTime;

pair<int, int> getFinishTime() {
	minute += cookTime;
	if (minute >= 60) {
		hour += minute / 60;
		minute = minute%60;
		hour %= 24;
	}
	return { hour, minute };
}

int main() {
	cin >> hour >> minute >> cookTime;
	pair<int, int> finishTime = getFinishTime();
	cout << finishTime.first <<' ' << finishTime.second << '\n';
}
