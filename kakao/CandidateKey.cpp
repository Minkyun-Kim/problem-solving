#include <string>
#include <vector>
#include <algorithm>

int countBit(int a){
    int ans = 0;
    while(a){
        if(a & 1)
            ans++;
        a = a >> 1;
    }
    return ans;
}

bool comp(int a, int b){
    return countBit(a) > countBit (b);
}

using namespace std;
bool findEqual(int key, vector<vector<string>> relation){
    for(int i = 0; i < relation.size()-1; i++){
        for(int j = i+1; j < relation.size(); j++){
            bool check = true;
            for(int k = 0; k < relation[0].size(); k++){
                if((key & 1 << k) == 0) continue;
                if(relation[i][k] != relation[j][k]){
                    check = false;
                    break;
                }
            }
            if(check) 
                return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> candidate;
    for(int key = 0; key < 1<<relation[0].size(); key++){
        if(findEqual(key, relation))
            candidate.push_back(key);
    }
    sort(candidate.begin(), candidate.end(), comp);
    
    while(!candidate.empty()){
        int n = candidate.back();
        candidate.pop_back();
        answer++;
        for(auto it = candidate.begin(); it != candidate.end();){
            if((*it & n) == n){
                candidate.erase(it);
            }
            else
                it++;
        }
    }
    return answer;
}
