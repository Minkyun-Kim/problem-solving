#include <string>
#include <vector>
#include <math.h>
using namespace std;

double StringToMintime(bool timeFlag, string time) {
	double secTime = 0;
	double msec = 0;
	int sec = 0;

	if (timeFlag == true) {
		int hour = ((time[0] - '0') * 10 + (time[1] - '0')) * 3600;
		int min = ((time[3] - '0') * 10 + (time[4] - '0')) * 60;
		sec = (time[6] - '0') * 10 + (time[7] - '0');
		msec = ((time[9] - '0') / pow(10, 1)) + ((time[10] - '0') / pow(10, 2)) + ((time[11] - '0') / pow(10, 3));
		secTime = (double)(hour + min + sec) + msec;
	}
	else {
		for (int i = 0; i < time.size() - 1; i++) {
			if (i == 0)     sec = (time[0] - '0');
			else if (i > 1) msec += (time[i] - '0') / pow(10, i - 1);
		}
		secTime = (double)sec + msec ;
	}

	return secTime;
}

int solution(vector<string> lines) {
	vector<double> startTime;
	vector<double> endTime;
	for (string s : lines) {
		startTime.push_back(StringToMintime(true, s.substr(11, 12)) - StringToMintime(false, s.substr(24)));
		endTime.push_back(StringToMintime(true, s.substr(11, 12)));
	}

	int answer = 0;
	int lineSize = lines.size();
	for (int i = 0; i < lineSize; i++) {
		double front = startTime[i];
		double end = front + 0.999;
		int temp = 0;
		for (int j = 0; j < lineSize; j++) {
			if (endTime[j] < front || end <= startTime[j])
				continue;
			temp++;
		}
		answer = answer < temp ? temp : answer;
		temp = 0;
		front = endTime[i];
		end = front + 0.999;
		for (int j = 0; j < lineSize; j++) {
			if (endTime[j] < front || end <= startTime[j])
				continue;
			temp++;
		}
		answer = answer < temp ? temp : answer;

	}
	return answer;
}
