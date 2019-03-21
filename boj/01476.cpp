#include <iostream>
using namespace std;

int main(){
	int e, s, m;
	cin >> e >> s >> m;
	int ans = 0;
	int i = 0, j = 0, k = 0;
	while(1){
		ans++;
		i = (i+1)%16;
		if(i == 0) i++;
		j = (j+1)%29;
		if(j==0) j++;
		k = (k+1)%20;
		if(k==0) k++;
		if(i == e && j == s && k == m){
			cout << ans << '\n';
			return 0;
		}


	}
}
