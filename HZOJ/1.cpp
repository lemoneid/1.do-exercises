#include <iostream>
#include <algorithm>
using namespace std;

#define out(frm) {\
    printf("%s = %p\n", #frm,frm);\
}

int main() {
    int **a = (int **) malloc (sizeof(int **) * 10);
    for (int i = 0; i < 10; ++i) {
        a[i] = (int *) malloc (sizeof(int *) * 3);
    }

    out(a);
    out(a[0]);
    out(a[1]);

    return 0;
}
