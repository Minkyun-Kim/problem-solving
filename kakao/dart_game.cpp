#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int curScore = 0;
    int scoreIdx = 0;
    vector<int> score(3);
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] == '1' && dartResult[i+1] == '0'){
                curScore = 10;
                i++;
            }
            else
                curScore = dartResult[i] - '0';
            score[scoreIdx] = curScore;
        }
        else {
            if(dartResult[i] == 'S');
            else if(dartResult[i] == 'D'){
                score[scoreIdx] *= curScore;
            }
            else if(dartResult[i] == 'T'){
                score[scoreIdx] *= curScore * curScore;
            }
            if(++i == dartResult.size())
                break;
            if(dartResult[i] == '#'){
                score[scoreIdx] *= -1;
            }
            else if(dartResult[i] == '*'){
                score[scoreIdx] *= 2;
                if(i != 2)
                    score[scoreIdx-1] *= 2;
            }
            else
                i--;
            scoreIdx++;
        }   
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}
