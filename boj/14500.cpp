#include <iostream>
using namespace std;

int n, m;
int arr[500][500];
int ans;

int blue1(int x, int y) {
	//  ㅡ
	if (y + 3 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x][y + 3];
}
int blue2(int x, int y) {
	//  ㅣ
	if (x - 3 < 0)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 3][y];
}
int red1(int x, int y) {
	//ㄴ
	if (x - 2 < 0)
		return -1;
	if (y + 1 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1]+ arr[x-1][y] + arr[x-2][y];
}
int red2(int x, int y) {
	//ㄱ거꾸로
	if (x - 1 < 0)
		return -1;
	if (y + 2 >= m)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x - 1][y + 2];
}
int red3(int x, int y) {
	if (y - 1 < 0)
		return -1;
	if (x - 2 < 0)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 2][y - 1];
}
int red4(int x, int y) {
	if (x - 1 < 0)
		return -1;
	if (y + 2 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x-1][y + 2];
}
int red5(int x, int y) {
	if (y + 1 >= m)
		return -1;
	if (x - 2 < 0)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x - 2][y + 1];
}
int red6(int x, int y) {
	if (y + 2 >= m)
		return -1;
	if (x + 1 >= n)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 2];
}
int red7(int x, int y) {
	if (x - 2 < 0)
		return -1;
	if (y + 1 >= m)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 2][y + 1];
}
int red8(int x, int y) {
	if (x - 1 < 0)
		return -1;
	if (y + 2 >= m)
		return-1;
	return arr[x][y] + arr[x - 1][y] + arr[x][y + 1] + arr[x][y + 2];
}
int yellow1(int x, int y) {
	if (x - 1 < 0)
		return -1;
	if (y + 1 >= m)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y + 1];
}
int green1(int x, int y) {
	if (y - 1 < 0)
		return -1;
	if (x - 2 < 0)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 1][y - 1] + arr[x - 2][y - 1];
}
int green2(int x, int y) {
	if (x - 1 < 0)
		return -1;
	if (y + 2 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x - 1][y + 2];
}
int green3(int x, int y) {
	if (x - 2 < 0)
		return -1;
	if (y + 1 >= m)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x - 2][y + 1];
}
int green4(int x, int y) {
	if (x + 1 >= n)
		return -1;
	if (y + 2 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
}
int purple1(int x, int y) {
	if (x - 1 < 0)
		return -1;
	if (y + 2 >= m)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 1];
}
int purple2(int x, int y) {
	if (x - 2 < 0)
		return -1;
	if (y + 1 >= m)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 1][y + 1];
}
int purple3(int x, int y) {
	if (y -1 <0)
		return -1;
	if (x - 2 < 0)
		return -1;
	return arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 1][y - 1];
}
int purple4(int x, int y) {
	if (y + 2 >= m)
		return -1;
	if (x + 1 >= n)
		return -1;
	return arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			temp = blue1(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = blue2(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red1(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red2(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red3(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red4(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red5(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red6(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red7(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = red8(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = yellow1(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = green1(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = green2(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = green3(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = green4(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = purple1(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = purple2(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = purple3(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
			temp = purple4(i, j);
			if (temp != -1) {
				ans = ans < temp ? temp : ans;
			}
		}
	}
	cout << ans << '\n';
}

