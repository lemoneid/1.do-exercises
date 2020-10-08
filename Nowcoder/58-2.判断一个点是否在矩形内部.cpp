
#include <bits/stdc++.h>
using namespace std;
 
typedef struct node {
    double x, y;
} node;

node point[5];

double get_angle(node p1, node p2) {
    return acos((p1.x * p2.x + p1.y * p2.y) / (sqrt(p1.x * p1.x + p1.y * p1.y) * sqrt(p2.x * p2.x + p2.y * p2.y)));
}

int main() {
    for (int i = 1; i < 5; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    cin >> point[0].x >> point[0].y;
    node vec[5];
    for (int i = 1; i < 5; ++i) {
        vec[i].x = point[i].x - point[0].x;
        vec[i].y = point[i].y - point[0].y;
    }
    double sum = get_angle(vec[1], vec[2]) + get_angle(vec[2], vec[4]) + get_angle(vec[4], vec[3]) + get_angle(vec[3], vec[1]);
    //cout << "sum = " << sum << " 2pi = " << acos(-1) * 2 << endl;
    if (fabs(sum - acos(-1) * 2) < 1e-6) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
