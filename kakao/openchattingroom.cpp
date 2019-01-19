#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
        vector<string> answer;
        string getRecord;
        vector<string> action;
        vector<string> who;
        map<string, string> id;
        for (int i = 0; i < record.size(); i++) {
                getRecord = record[i];
                string token[3];
                for (int i = 0; i < 3; i++) {
                        int pos = getRecord.find(" ");
                        if (pos == string::npos) {
                                token[i] = getRecord;
                                break;
                        }
                        token[i] = getRecord.substr(0, pos);
                        getRecord.erase(0, pos + 1);
                }
                if (token[0] == "Enter") {
                        action.push_back(token[0]);
                        id[token[1]] = token[2];
                        who.push_back(token[1]);
                }
                else if (token[0] == "Leave") {
                        action.push_back(token[0]);
                        who.push_back(token[1]);
                }
                else {
                        id[token[1]] = token[2];
                }
        }
        for (int i = 0; i < action.size(); i++) {
                if (action[i] == "Enter") {
                        answer.push_back(id[who[i]]);
                        answer[i].append("님이 들어왔습니다.");

                }
                else {
                        answer.push_back(id[who[i]]);
                        answer[i].append("님이 나갔습니다.");
                }
        }
        return answer;
}