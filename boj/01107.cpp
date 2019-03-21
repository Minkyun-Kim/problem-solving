#include <iostream>
using namespace std;

int arr[10];
int m;

int possible(int c){
	if(c==0){
		for(int i = 0; i < m; i++){
			if(arr[i] == 0)
				return 0;
		}
		return 1;
	}
	int len = 0;
	while(c>0){
		len++;
		int mod = c%10;
		for(int i = 0; i < m; i++){
			if(mod == arr[i])
				return 0;
		}
		c /= 10;
	}
	return len;
}

int main(){
	int n;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin>> arr[i];
	}
	int mini = n > 100 ? n - 100 : 100 - n;
	for(int i = 0; i <= 1000000; i++){
		int len = possible(i);
		if(len){
			int temp = len + (i > n ? i-n : n-i);
			mini = mini > temp ? temp : mini;
		}
	}
	cout << mini << '\n';
	return 0;
}
