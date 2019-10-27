#include<iostream>
#include<string>
using namespace std;

int n, number, strike, ball;
bool arr[1000];
string tmp, one, two;
int strike_cnt, ball_cnt, ans;

void initArr() {
	for (int i = 0; i < 1000; i++) {
		arr[i] = true;
	}
}

int main(){
	cin >> n;
	initArr();
	for (int i = 123; i <= 999; i++){
		tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			arr[i] = false;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
			arr[i] = false;
	}
	for (int i = 1; i <= n; i++){
		cin >> number >> strike >> ball;
		for (int i = 123; i <= 999; i++){
			strike_cnt = 0;
			ball_cnt = 0;
			if (arr[i]){
				one = to_string(number);
				two = to_string(i);
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && one[x] == two[y])
							strike_cnt++;
						if (x != y && one[x] == two[y])
							ball_cnt++;
					}
				}
				if (strike_cnt != strike || ball_cnt != ball)
					arr[i] = false;
			}
		}
	}
	for (int i = 123; i <= 999; i++){
		if (arr[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
