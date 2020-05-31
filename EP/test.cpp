#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define max_n 10000

long long Triangle(long long n) {
    return (n * (n + 1) / 2);
}

long long Pentagonal(long long n) {
    return (n * (3 * n - 1) / 2);
}

long long  Hexagonal(long long n) {
    return (n * (2 * n -1));
}

int binarysearch(long long (*f)(long long ), long long  value) {
    long long  l = 1, r  = value, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (f(mid) == value) return 1;
        if (f(mid) > value) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}


int main() {
    long long  temp;
    for (int i = 144; ; ++i) {
        temp = Hexagonal(i);
        cout << temp << endl;
        if(binarysearch(Pentagonal, temp) && binarysearch(Triangle, temp)) {
            break;
        }
    }
    cout << temp << endl;
    return 0;
}
