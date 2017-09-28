#include <iostream>
#include <string>

using namespace std;



class Stack
{
	int arr[100000];
	int top = 0;

public:
	void push(int a)
	{
		
		arr[++top] = a;
	}
	void pop()
	{
		if (top == 0)
			cout << "-1" << endl;
		else
		{
			cout << arr[top--] << endl;
		}
	}
	void size()
	{
		cout << top << endl;
	}
	void empty()
	{
		if (top == 0)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	void Top()
	{
		if (top == 0)
			cout <<"-1" << endl;
		else
			cout << arr[top] << endl;
	}
};

int main()
{
	Stack stack;
	int n;
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			int k;
			cin >> k;
			stack.push(k);
		}
		else if (input == "top") {
			stack.Top();
		}
		else if (input == "size") {
			stack.size();
		}
		else if (input == "empty") {
			stack.empty();
		}
		else 
			stack.pop();
		
	}
	return 0;

}


