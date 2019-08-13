#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct Node {
	int value;
	Node* left;
	Node* right;
}Node;

Node* root;
int cnt = 0;

void insert(Node* ptr, int value) {
	if ((*ptr).value < value) {
		if ((*ptr).right == nullptr) {
			(*ptr).right = new Node();
			(*ptr).right->value = value;
			return;
		}
		else {
			insert(ptr->right, value);
		}
	}
	else {
		if (ptr->left == nullptr) {
			ptr->left = new Node();
			ptr->left->value = value;
			return;
		}
		else {
			insert(ptr->left, value);
		}
	}
}
void postOrder(Node* ptr) {
	if (ptr->left != nullptr)
		postOrder(ptr->left);
	if (ptr->right != nullptr)
		postOrder(ptr->right);
	cout << ptr->value << '\n';
}
int main() {
	int value;
	scanf("%d", &value);
	Node top = { value, nullptr, nullptr };
	root = &top;
	cnt++;
	while (scanf("%d", &value) != EOF) {
		cnt++;
		insert(root, value);

	}
	postOrder(root);

}
