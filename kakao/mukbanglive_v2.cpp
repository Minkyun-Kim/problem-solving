#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
        
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> sorted;
    for(int i = 0; i < food_times.size(); i++){
        sorted.push_back(make_pair(food_times[i], i+1));
    }
    sort(sorted.begin(), sorted.end());
    int pos = 0;
    int n = sorted.size();
    for(auto it = sorted.begin(); it != sorted.end(); it++,n-- ){
        long long vol = (long long)(it->first-pos)*n;
        if(vol == 0)
            continue;
        if(vol <= k){
            k -= vol;
            pos = it->first;
        }
        else{
            k %= n;
            sort(it, sorted.end(), cmp);
            return (it+k)->second;
        }
    }
    
    return -1;
}