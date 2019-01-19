#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s;
	stack<char> st;
	cin>>s;
	int part=0;
	for(int i=0; i<s.size();i++){
		if(s[i]=='('){
			st.push(s[i]);
		}
		else{
			if(s[i-1]=='('){
				st.pop();
				part+=st.size();
			}
			else if(s[i-1]==')'){
				st.pop();
				part++;
			}
		}
	}
	cout<<part<<endl;
}
