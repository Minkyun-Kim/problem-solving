#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

bool findCity(deque<string>& cache, string city, int cacheSize){
    bool answer = false;
    stack<string> temp;
    while(!cache.empty()){
        if(cache.front() == city){
            cache.push_back(cache.front());
            cache.pop_front();
            answer = true;
            break;
        }
        else{
            temp.push(cache.front());
            cache.pop_front();
        }
    }
    while(!temp.empty()){
        cache.push_front(temp.top());
        temp.pop();
    }
    if(!answer){
        if(cache.size() >= cacheSize){
            if(cacheSize != 0)
                cache.pop_front();
        }
        if(cacheSize != 0)
            cache.push_back(city);
    }
    return answer;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    for(int i = 0; i < cities.size(); i++){
        string city = cities[i];
        for(int j = 0; j < city.size(); j++){
            city[j] = tolower(city[j]);
        }
        if(findCity(cache, city, cacheSize))
            answer += 1;
        else
            answer += 5;
    }
    return answer;
}
