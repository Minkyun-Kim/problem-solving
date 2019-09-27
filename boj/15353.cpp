#include <iostream>
#include <string>
#include <queue>
using namespace std;

string s1, s2;
bool s1Sign, s2Sign;
deque<char> ans;

int main() {
	cin >> s1 >> s2;
	if (s1[0] == '-')
		s1Sign = true;
	if (s2[0] == '-')
		s2Sign = true;

  int s1Size = s1.size();
  s1Size--;
  int s2Size = s2.size();
  s2Size--;
  int carry = 0;
  while (s1Size >= 0 && s2Size >= 0) {
    int temp = s1[s1Size] - '0' + s2[s2Size] - '0' + carry;
    carry = 0;
    if (temp >= 10) {
      carry = 1;
      temp -= 10;
    }
    ans.push_front(temp);
    s1Size--;
    s2Size--;
  }
  while (s1Size >= 0) {
    int temp = s1[s1Size]-'0' + carry;
    carry = 0;
    if (temp >= 10) {
      carry = 1;
      temp -= 10;
    }
    ans.push_front(temp);
    s1Size--;
  }
  while (s2Size >= 0) {
    int temp = s2[s2Size]-'0' + carry;
    carry = 0;
    if (temp >= 10) {
      carry = 1;
      temp -= 10;
    }
    ans.push_front(temp);
    s2Size--;
  }
  if (carry)
    ans.push_front(carry);
  if (s1Sign)
    cout << '-';
  for (char c : ans) {
    cout << (char)(c+'0');
  }
  cout << '\n';


}
