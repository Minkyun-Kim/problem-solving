#include <iostream>
#include <cstdio>
using namespace std;
int sbridge[101];

int main() {
    int money, n;
    cin >> money >> n;
    for (int i = 0; i < n; i++) {
        int start;
        char direction;
        cin >> start >> direction;
        if (direction == 'R') {
            for (int i = start + 1; i <= 100; i++) {
                sbridge[i]++;
            }
        }
        else {
            for (int i = start - 1; i >= 1; i--) {
                sbridge[i]++;
            }
        }
    }
    int blue = 0, red = 0, green = 0;
    for (int i = 1; i <= 100; i++) {
        sbridge[i] %= 3;
        switch (sbridge[i]) {
            case 0:
                blue++;
                break;
            case 1:
                red++;
                break;
            case 2:
                green++;
                break;
        }
    }
    float big = (float)blue / 100*money;
    float mid = (float)red / 100 * money;
    float small = (float)green / 100 * money;
    printf("%.2f\n%.2f\n%.2f\n", big, mid, small);
    return 0;


}
