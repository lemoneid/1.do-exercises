#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    vector<int> arr;
    deque<int> q;
    cin >> n >> k;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && arr[i] <= arr[q.back()]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i < k - 1) continue;
        i != k - 1 && cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    while (!q.empty()) q.pop_front();
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i < k - 1) continue;
        i != k - 1 && cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    return 0;
}