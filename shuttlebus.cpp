#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sToMin(string s) {
	int min = 0;
	min += (s[0] - '0') * 10 * 60;
	min += (s[1] - '0') * 60;
	min += (s[3] - '0') * 10;
	min += s[4] - '0';
	return min;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int bus[11] = { 0, };
	int start = 540;
	int end = start + t*(n - 1);
	int vSize = timetable.size();
	vector<int> crew;
	for (int i = 0; i < vSize; i++) {
		crew.push_back(sToMin(timetable[i]));
    }

	sort(crew.begin(), crew.end());
    
    int aboardCrew = 0;
    int busTime = start;
    int answerTime = 0;
    for(int i = 0; i < n; i++){
        int remainSeat = m;
        for(int j = aboardCrew; j < crew.size(); j++){
            if(crew[j]<= busTime){
                remainSeat--;
                aboardCrew++;
                if(remainSeat==0)
                    break;
            }
        }
        if(i == n-1){
            if(remainSeat == 0)
                answerTime = crew[aboardCrew-1]-1;
            else
                answerTime = busTime;
            
        }
        busTime += t;
        if(busTime >= 60*24)
            break;
    }

	int hour = answerTime / 60;
	int min = answerTime % 60;

	answer.push_back((hour / 10) + '0');
	answer.push_back((hour % 10) + '0');
	answer.push_back(':');
	answer.push_back((min / 10) + '0');
	answer.push_back((min % 10) + '0');
	
	return answer;
}
