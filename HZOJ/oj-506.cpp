/*************************************************************************
	> File Name: oj-506.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 09时12分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 30

struct student {
    int loc;
    int time;
} stu[max_n + 5];

bool cmp(struct student a, struct student b) {
    return a.time < b.time;
}

int main() {
    int n, temp;
    cin >> n;
    double ans = 0;
    long long sum[max_n + 5] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        stu[i].loc = i + 1;
        stu[i].time = temp;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        !i || cout << " ";
        cout << stu[i].loc;
        if (i > 0) sum[i] = sum[i - 1] + stu[i - 1].time; 
    }
    cout << endl;
    for (int i = 1; i < n; ++i)
        ans += sum[i];
    printf("%.2lf\n", ans / n);
    return 0;
}
