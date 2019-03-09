#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0; i < n; i++){
        int sec = arr1[i] | arr2[i];
        for(int j = 0; j < n; j++){
            if((sec & 1) == 1){
                answer[i] = "#" + answer[i];
            }
            else{
                answer[i] = " " + answer[i];
            }
            sec >>= 1;
        }
    }
    return answer;
}
