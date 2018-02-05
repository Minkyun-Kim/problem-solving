#include <iostream>
#include <vector>
using namespace std;
vector<vector<char> > v(26, vector<char>(2));

void preorder(char c){
    cout << c;
    if(v[c-'A'][0] != 0) 
        preorder(v[c-'A'][0]);
    if(v[c-'A'][1] != 0)
        preorder(v[c-'A'][1]);
}

void inorder(char c){
    if(v[c-'A'][0] != 0)
        inorder(v[c-'A'][0]);
    cout << c;
    if(v[c-'A'][1] != 0)
        inorder(v[c-'A'][1]);
}

void postorder(char c){
    if(v[c-'A'][0] != 0)
        postorder(v[c-'A'][0]);
    if(v[c-'A'][1] != 0)
        postorder(v[c-'A'][1]);
    cout << c;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        char c[3];
        cin >> c[0] >> c[1] >> c[2];
        if(c[1] != '.')
            v[c[0]-'A'][0] = c[1];
        if(c[2] != '.')
            v[c[0]-'A'][1] = c[2];
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
    return 0;
}
