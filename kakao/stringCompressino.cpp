#include <string>
#include <vector>
using namespace std;

bool isSame(int start1, int start2, int unit, string s) {
	for (int i = 0; i < unit; i++) {
		if (s[i + start1] != s[i + start2])
			return false;
	}
	return true;
}

int solution(string s) {
    if(s.size()==1)
        return 1;
	int answer = 1001;
	int unit = s.size() / 2 + 1;
	while (--unit) {
		int i = 0;
		string temp;
		while (i + 2 * unit <= s.size()) {
			int count = 1;
			while (isSame(i, i + unit * count, unit, s)) {
				count++;
			}
			if (count != 1) {
				int t = count;
				if (count >= 1000) {
					temp.push_back(count / 1000 + '0');
					count %= 1000;
				}
				if (count >= 100) {
					temp.push_back(count / 100 + '0');
					count %= 100;
				}
				if (count >= 10) {
					temp.push_back(count / 10 + '0');
					count %= 10;
				}
				temp.push_back(count % 10 + '0');
				count = t;
			}
			for (int j = 0; j < unit; j++) {
				temp.push_back(s[i + j]);
			}
			i += count * unit;

		}
		while (i < s.size()) {
			temp.push_back(s[i++]);
		}
		if (answer > temp.size())
			answer = temp.size();
	}


	return answer;
}
