#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    if(a < b){
        return true;
    }
    else
        return false;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), desc);   
    for(int i = 0; i < d.size(); i++){
        if(d[i] <= budget){
            budget -= d[i];
            answer ++;
        }
        else
            return answer;
    }
    return answer;
}
