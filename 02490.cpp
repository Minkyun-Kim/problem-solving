#include <iostream>
using namespace std;

int main(){
    int n, yoot;
    for(int i = 0; i < 3; i++){
        n = 0;
        yoot = 0;
        for(int j = 0; j < 4; j++){
            cin >> yoot;
            if(yoot == 0)
                n++;
        }
        switch(n){
            case 0:
                cout << "E" << '\n';
                break;
            case 1:
                cout << "A" << '\n';
                break;
            case 2:
                cout << "B" << '\n';
                break;
            case 3:
                cout << "C" << '\n';
                break;
            case 4:
                cout << "D" << '\n';
                break;
        }
    }
    return 0;
}
