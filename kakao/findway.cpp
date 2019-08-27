#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
	int id;
	int x;
	int y;
	int left;
	int right;
}Node;

Node nodes[10000];

bool comp(Node a, Node b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

vector<vector<int>> answer(2);
void pre(int idx) {
	answer[0].push_back(nodes[idx].id+1);
	if(nodes[idx].left != 0)
		pre(nodes[idx].left);
	if(nodes[idx].right != 0)
		pre(nodes[idx].right);
}
void post(int idx) {
	if(nodes[idx].left != 0)
		post(nodes[idx].left);
	if(nodes[idx].right != 0)
		post(nodes[idx].right);
	answer[1].push_back(nodes[idx].id+1);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int nodeSize = nodeinfo.size();
	for (int i = 0; i < nodeSize; i++) {
		nodes[i].id = i;
		nodes[i].x = nodeinfo[i][0];
		nodes[i].y = nodeinfo[i][1];
	}
	sort(nodes, nodes + nodeSize, comp);
	for (int i = 1; i < nodeSize; i++) {
		int x = nodes[i].x;
		int idx = 0;
		while (1) {
			//왼쪽 서브트리로 갈 경우
			if (x < nodes[idx].x) {
				if(nodes[idx].left == 0){
					nodes[idx].left = i;
					break;
				}
				else {
					idx = nodes[idx].left;
				}
			}
			//오른쪽 서브트리로 갈 경우
			else {
				if (nodes[idx].right == 0) {
					nodes[idx].right = i;
					break;
				}
				else {
					idx = nodes[idx].right;
				}
			}
		}
	}
	
	pre(0);
	post(0);
	return answer;
}
