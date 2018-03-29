#include <iostream>
using namespace std;

int main() {
    char** ch = new char*[5];
    for (int i = 0; i < 5; i++) {
        ch[i] = new char[16];
        cin >> ch[i];
    }
    for (int i = 0; i < 15; i++) {
        if ((ch[0][i] >= 65 && ch[0][i] <= 90) || (ch[0][i] >= 94 && ch[0][i] <= 122) || (ch[0][i] >= 48 && ch[0][i] <= 57))
            cout << ch[0][i];
        if ((ch[1][i] >= 65 && ch[1][i] <= 90) || (ch[1][i] >= 94 && ch[1][i] <= 122) || (ch[1][i] >= 48 && ch[1][i] <= 57))
            cout << ch[1][i];
        if ((ch[2][i] >= 65 && ch[2][i] <= 90) || (ch[2][i] >= 94 && ch[2][i] <= 122) || (ch[2][i] >= 48 && ch[2][i] <= 57))
            cout << ch[2][i];
        if ((ch[3][i] >= 65 && ch[3][i] <= 90) || (ch[3][i] >= 94 && ch[3][i] <= 122) || (ch[3][i] >= 48 && ch[3][i] <= 57))
            cout << ch[3][i];
        if ((ch[4][i] >= 65 && ch[4][i] <= 90) || (ch[4][i] >= 94 && ch[4][i] <= 122) || (ch[4][i] >= 48 && ch[4][i] <= 57))
            cout << ch[4][i];
    }
    cout << '\n';
    return 0;
}


