#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> already;
    int turn = 0;
    for(int i = 0; i < words.size(); i++){
        turn++;
        if(turn > n)
            turn = 1;
        int size;
        if(i != 0){
            size = words[i-1].length();
        	if(words[i-1][size-1] != words[i][0]){
         	   	answer.push_back(turn);
            	answer.push_back(i/n + 1);
            	return answer;
       		 }
        }
		for(int j = 0; j < already.size(); j++){
            if(already[j] == words[i]){
                answer.push_back(turn);
                answer.push_back(i/n + 1);
                return answer;
            }
        }        
        already.push_back(words[i]);
    }
	answer.push_back(0);
    answer.push_back(0);
    return answer;
}
