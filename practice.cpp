#include <iostream>
using namespace std;
void func(int n1=1, int n2=2, int n3){
    cout << "func1"<<'\n';
}
/*void func(int n1, int n2){
    cout << "func2"<< '\n';
}
*/
int main(){
    func(1, 2,3);
}
