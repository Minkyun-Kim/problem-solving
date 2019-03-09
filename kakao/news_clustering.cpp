#include <string>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> ms1;
    multiset<string> ms2;
   
    for(int i= 0; i < str1.size()-1; i++){
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            string s = "";
            s += tolower(str1[i]);
            s += tolower(str1[i+1]);
            ms1.insert(s);
        }
    }
    for(int i= 0; i < str2.size()-1; i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            string s = "";
            s += tolower(str2[i]);
            s += tolower(str2[i+1]);
            ms2.insert(s);
        }
    }
    multiset<string> s;
    set_intersection(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), inserter(s, s.end()));
    multiset<string> s1;
    set_union(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), inserter(s1, s1.end()));
    if(s.size() == 0 && s1.size() == 0)
        answer = 65536;
    else{
        answer = (double)s.size()/s1.size()*65536;
    }
    return answer;
}
