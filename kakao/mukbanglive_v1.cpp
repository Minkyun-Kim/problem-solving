#include <string>
#include <vector>

using namespace std;

vector<int>::iterator find_next(vector<int>::iterator it, vector<int> &food_times){
    for(int i = 0; i < food_times.size(); i++){//size를 변수로 빼면 효율성이 좋아질까?
        if(it == food_times.end()){
            it = food_times.begin();
        }
        if(*it != 0)
            return it;
        else
            it++;
        if(i == food_times.size())
            return food_times.end();
    }
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    auto it = food_times.begin();
    while(k--){
        (*it)--;
        if((it = find_next(++it, food_times)) == food_times.end()){
            answer = -1;
            return answer; 
        }
        
    } 
    answer = it - food_times.begin() + 1;
    return answer;
}