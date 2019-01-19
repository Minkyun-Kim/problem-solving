#include <iostream>
using namespace std;
int a[10][10];

int main(){
    int row = 1, col = 1;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> a[i][j];
            if(a[row][col] < a[i][j]){
                row = i;
                col = j;
            }
        }
    }
    cout << a[row][col] << '\n' << row << " " << col << '\n';
    return 0;
}
