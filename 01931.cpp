#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting{
    int begin, end;
    Meeting(int s, int e):begin(s), end(e){}
};

bool cmp(Meeting &u, Meeting &v){
    if(u.end == v.end){
        return u.begin < v.begin;
    }
    else{
        return u.end < v.end;
    }
}

int main(){
    int n;
    cin >> n;
    vector<Meeting> v;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(Meeting(start, end));
    }
    sort(v.begin(), v.end(), cmp);
    int end = 0, mt = 0;
    for(int i = 0; i < v.size(); i++){
        if(end <= v[i].begin){
            end =v[i].end;
            mt++;
        }
    }
    cout << mt << '\n';
    return 0;    
}
