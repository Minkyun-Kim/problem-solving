#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[8][8];
int ans = 64;
int cnt;
vector<pair<int, pair<int, int> > > v;

void look0(int x, int y) {
	for (int j = x-1; j >= 0; j--) {
		if (arr[j][y] == 6) {
			break;
		}
		else if(arr[j][y] > 0){
			continue;
		}
		else {
			arr[j][y]--;
		}
	}
	return;
}

void nolook0(int x, int y) {
	for (int j = x-1; j >= 0; j--) {
		if (arr[j][y] == 6) {
			break;
		}
		else if(arr[j][y] > 0){
			continue;
		}
		else {
			arr[j][y]++;
		}
	}
	return;
}

void look1(int x, int y) {
	for (int j = y+1; j <m; j++) {
		if (arr[x][j] == 6) {
			break;
		}
		else if(arr[x][j] > 0){
			continue;
		}
		else {
			arr[x][j]--;
		}
	}
	return;

}

void nolook1(int x, int y) {
	for (int j = y+1; j <m; j++) {
		if (arr[x][j] == 6) {
			break;
		}
		else if(arr[x][j] > 0){
			continue;
		}
		else {
			arr[x][j]++;
		}
	}
	return;
}
void look2(int x, int y) {
	for (int j = x+1; j < n; j++) {
		if (arr[j][y] == 6) {
			break;
		}
		else if(arr[j][y] > 0){
			continue;
		}
		else {
			arr[j][y]--;
		}
	}
	return;

}
void nolook2(int x, int y) {
	for (int j = x+1; j < n; j++) {
		if (arr[j][y] == 6) {
			break;
		}
		else if(arr[j][y] > 0){
			continue;
		}
		else {
			arr[j][y]++;
		}
	}
	return;
}

void look3(int x, int y) {
	for (int j = y-1; j >= 0; j--) {
		if (arr[x][j] == 6) {
			break;
		}
		else if(arr[x][j] > 0){
			continue;
		}
		else {
			arr[x][j]--;
		}
	}
	return;

}
void nolook3(int x, int y) {
	for (int j = y-1; j >= 0; j--) {
		if (arr[x][j] == 6) {
			break;
		}
		else if(arr[x][j] > 0){
			continue;
		}
		else {
			arr[x][j]++;
		}
	}
	return;
}
int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}
void eye(int i) {
	if (i == v.size()) {
		cnt = count();
		if (ans > cnt) {
			ans = cnt;
		}
		return;
	}
	else {
		int cam = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;
		if (cam == 1) {
			look0(x, y);
			eye(i+1);
			nolook0(x, y);
			look1(x, y);
			eye(i + 1);
			nolook1(x, y);
			look2(x, y);
			eye(i+1);
			nolook2(x, y);
			look3(x, y);
			eye(i + 1);
			nolook3(x, y);

		}
		else if (cam == 2) {
			look0(x, y);
			look2(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook2(x, y);
			look1(x, y);
			look3(x, y);
			eye(i + 1);
			nolook1(x, y);
			nolook3(x, y);

		}
		else if (cam == 3) {
			look0(x, y);
			look1(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook1(x, y);
			look1(x, y);
			look2(x, y);
			eye(i + 1);
			nolook1(x, y);
			nolook2(x, y);
			look2(x, y);
			look3(x, y);
			eye(i + 1);
			nolook2(x, y);
			nolook3(x, y);
			look3(x, y);
			look0(x, y);
			eye(i + 1);
			nolook3(x, y);
			nolook0(x, y);
		}
		else if (cam == 4) {
			look0(x, y);
			look1(x, y);
			look2(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook1(x, y);
			nolook2(x, y);
			look3(x, y);
			look1(x, y);
			look2(x, y);
			eye(i + 1);
			nolook3(x, y);
			nolook1(x, y);
			nolook2(x, y);
			look0(x, y);
			look3(x, y);
			look2(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook3(x, y);
			nolook2(x, y);
			look0(x, y);
			look1(x, y);
			look3(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook1(x, y);
			nolook3(x, y);
		}
		else if (cam == 5) {
			look0(x, y);
			look1(x, y);
			look2(x, y);
			look3(x, y);
			eye(i + 1);
			nolook0(x, y);
			nolook1(x, y);
			nolook2(x, y);
			nolook3(x, y);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
				v.push_back(make_pair(arr[i][j], make_pair(i, j)));
		}
	}
	if (v.size() == 0) {
		cout << count() << '\n';
		return 0;
	}
	int cam = v[0].first;
	int x = v[0].second.first;
	int y = v[0].second.second;
	if (cam == 1) {
		look0(x, y);
		eye(1);
		nolook0(x, y);
		look1(x, y);
		eye(1);
		nolook1(x, y);
		look2(x, y);
		eye(1);
		nolook2(x, y);
		look3(x, y);
		eye(1);
		nolook3(x, y);

	}
	else if (cam == 2) {
		look0(x, y);
		look2(x, y);
		eye(1);
		nolook0(x, y);
		nolook2(x, y);
		look1(x, y);
		look3(x, y);
		eye(1);
		nolook1(x, y);
		nolook3(x, y);

	}
	else if (cam == 3) {
		look0(x, y);
		look1(x, y);
		eye(1);
		nolook0(x, y);
		nolook1(x, y);
		look1(x, y);
		look2(x, y);
		eye(1);
		nolook1(x, y);
		nolook2(x, y);
		look2(x, y);
		look3(x, y);
		eye(1);
		nolook2(x, y);
		nolook3(x, y);
		look3(x, y);
		look0(x, y);
		eye(1);
		nolook3(x, y);
		nolook0(x, y);
	}
	else if (cam == 4) {
		look0(x, y);
		look1(x, y);
		look2(x, y);
		eye(1);
		nolook0(x, y);
		nolook1(x, y);
		nolook2(x, y);
		look3(x, y);
		look1(x, y);
		look2(x, y);
		eye(1);
		nolook3(x, y);
		nolook1(x, y);
		nolook2(x, y);
		look0(x, y);
		look3(x, y);
		look2(x, y);
		eye(1);
		nolook0(x, y);
		nolook3(x, y);
		nolook2(x, y);
		look0(x, y);
		look1(x, y);
		look3(x, y);
		eye(1);
		nolook0(x, y);
		nolook1(x, y);
		nolook3(x, y);
	}
	else if(cam == 5){
		look0(x, y);
		look1(x, y);
		look2(x, y);
		look3(x, y);
		eye(1);
		nolook0(x, y);
		nolook1(x, y);
		nolook2(x, y);
		nolook3(x, y);
	}
	cout << ans << '\n';
	return 0;
}
