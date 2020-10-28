/*************************************************************************
	> File Name: oj-540.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 22时59分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 3000000
int n, x, pri[45], set[2][max_n + 5], cnt[2];

void func(int set_num, int start, int end, int sum) {
    if (sum > x) return ;
    for (int i = start; i < end; ++i) {
        sum += pri[i];
        set[set_num][cnt[set_num]] = sum;
        cnt[set_num] += 1;
        func(set_num, i + 1, end, sum);
        sum -= pri[i];
    }
    return ;
}

int main() {
    while (cin >> n >> x) {
        cnt[0] = cnt[1] = 1;
        for (int i = 0; i < n; ++i) cin >> pri[i];
        func(0, 0, n / 2, 0);
        func(1, n / 2, n, 0);
        sort(set[1], set[1] + cnt[1]);
        int flag = 0;
        for (int i = 0; i < cnt[0]; ++i) {
            int target = x - set[0][i];
            int l =  0, r = cnt[1] - 1, mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (set[1][mid] == target) {
                    flag = 1;
                    break;
                }
                if (set[1][mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            if (flag == 1) break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
