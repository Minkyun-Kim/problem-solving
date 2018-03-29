#include <iostream>
using namespace std;
int a[102];

int main() {
    int n;
    cin >> n;
    int cute = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            cute++;
    }
    if (cute > n - cute)
        cout << "Junhee is cute!" << '\n';
    else
        cout << "Junhee is not cute!" << '\n';
    return 0;
}
