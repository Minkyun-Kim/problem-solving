#include <iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	int*p = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < num-1; i++) {
		int j = i + 1;
		while (1) {
			if (p[i] > p[j]) {
				int tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
			j++;
			if (j == num)
				break;
		}

		}
	for (int i = 0; i < num; i++)
		cout << p[i] << endl;
	}





