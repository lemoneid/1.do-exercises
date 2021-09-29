/*************************************************************************
	> File Name: hj67.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 09时10分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool visit[5];
bool dfs(vector<int> &arr, int step, double sum,  double target) {
    if (sum == target && step == 4) return true;
    for (int i = 0; i < arr.size(); i++) {
        if (i && arr[i] == arr[i - 1] && visit[i - 1] == false) continue;
        if (visit[i] == true) continue;
        visit[i] = true;
        if (dfs(arr, step + 1, sum + arr[i], target)
           || dfs(arr, step + 1, sum - arr[i], target)
           || dfs(arr, step + 1, sum * arr[i], target)
           ) return true;
        if (sum != 0 && arr[i] != 0) dfs(arr, step, sum / arr[i], target);
        visit[i] = false;
    }
    return false;
}

int main() {
    vector<int> arr(4);
    while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]) {
        memset(visit, false, sizeof(visit));
        sort(arr.begin(), arr.end());
        cout << (dfs(arr, 0, 0, 24) ? "true" : "false") << endl;
    }
    return 0;
}
