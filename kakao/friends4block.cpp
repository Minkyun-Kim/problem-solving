#include <string>
#include <vector>

using namespace std;
int check[31][31];
void resetCheck(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			check[i][j] = 0;
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int temp = m;
	m = n;
	n = temp;
	resetCheck(n, m);
	int answer = 0;
	while (1) {
		int flag = 1;
		for (int i = 0; i <n-1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (board[i][j] != '0' && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
					flag = 0;
					check[i][j] = check[i][j + 1] = check[i + 1][j] = check[i + 1][j + 1] = 1;
				}
			}
		}
		for (int i = 0; i < m ; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (check[j][i] == 1) {
					int col = i;
					int row = j;


					while (check[row][col] != 0) {
						row--;
						if (row < 0)
							break;
					}
					if (row < 0) {
						board[j][i] = '0';
						check[j][i] = 0;
					}
					else {
						check[j][i] = 0;
						check[row][col] = 1;
						board[j][i] = board[row][col];
						board[row][col] = '0';
					}
				}
			}
		}


		if (flag)
			break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '0')
				answer++;
		}
	}
	return answer;
}
