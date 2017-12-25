#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main(){
    map<string, pair<long long, long long>> mp;
    mp["black"] = {0, 1};
    mp["brown"] = {1, 10};
    mp["red"] = {2, 100};
    mp["orange"] = {3, 1000};
    mp["yellow"] = {4, 10000};
    mp["green"] = {5, 100000};
    mp["blue"] = {6, 1000000};
    mp["violet"] = {7, 10000000};
    mp["grey"] = {8, 100000000};
    mp["white"] = {9, 1000000000};

    string color_1, color_2, weight;
    cin >> color_1 >> color_2 >> weight; 
    printf("%lld\n", (mp[color_1].first * 10 + mp[color_2].first) * mp[weight].second);
    return 0;

}
