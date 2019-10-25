#include <iostream>
#include <string>
using namespace std;

int arr[1001][1001];
string s1, s2;

int _max3(int x, int y) {
	int num1 = arr[x - 1][y];
	int num2 = arr[x][y - 1];
	int num3 = arr[x - 1][y - 1];
	if (s1[x - 1] == s2[y - 1])
		num3++;
	if (num1 > num2) {
		return num1 > num3 ? num1 : (num2 > num3 ? num2 : num3);
	}
	else {
		return num2 > num3 ? num2 : (num3 > num1 ? num3 : num1);
	}
}

int main() {
	cin >> s1 >> s2;
	int s1Size = s1.length();
	int s2Size = s2.length();

	for (int i = 1; i <= s1Size; i++) {
		for (int j = 1; j <= s2Size; j++) {
			arr[i][j] = _max3(i, j);
		}
	}
	cout << arr[s1Size][s2Size] << '\n';
	

}
