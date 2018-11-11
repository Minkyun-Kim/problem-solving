#include <cstdio>
#include <ctime>
using namespace std;

int main() {
    struct tm *t;
    time_t timer = time(0);
    t = localtime(&timer);
    printf("%d-%02d-%02d", t->tm_year+1900, t->tm_mon +1, t->tm_mday);
    return 0;
}
