#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int weight;
	int height;
	int bigger = 1;
}_pair;

_pair person[50];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person[i].weight >> person[i].height;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (person[i].weight < person[j].weight&& person[i].height < person[j].height)
				person[i].bigger++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << person[i].bigger << ' ';
	}
	cout << '\n';


}
