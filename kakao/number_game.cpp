#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b){
    if(a > b)
        return true;
    else
        return false;
}
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), desc);
    sort(B.begin(), B.end(), desc);
    auto a = A.begin();
    auto b_front = B.begin();
    auto b_end = B.end()-1;
    for(int i = 0; i < A.size(); i++){
     	if(*a < *b_front){
			answer++;
            a++;
            b_front++;
        }   
        else{
            a++;
            b_end--;
        }
    }
    return answer;
}
