#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
bool desc(pair<float, int> a, pair<float, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> rate = vector<pair<float, int>>(N, make_pair(0., 0));
	vector<int> numOfpeople = vector<int>(N + 1, 0.);
	for (int i = 0; i < stages.size(); i++) {
		numOfpeople[stages[i] - 1]++;
	}
	int leftPeople = stages.size();
	for (int i = 0; i < N; i++) {
		if (numOfpeople[i] == 0)
			rate[i] = make_pair(0, i + 1);
		else {
			rate[i].first = (float)numOfpeople[i] / leftPeople;
			rate[i].second = i + 1;
		}
		leftPeople -= numOfpeople[i];
	}
	sort(rate.begin(), rate.end(), desc);
	for (int i = 0; i < N; i++) {
		answer.push_back(rate[i].second);
	}

	return answer;
}
