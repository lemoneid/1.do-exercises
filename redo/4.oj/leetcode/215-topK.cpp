/*************************************************************************
	> File Name: 215-topK.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月17日 星期三 14时27分19秒
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
#include <time.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            return quickSelect(nums, 0, nums.size(), nums.size() - k);
    }
    int quickSelect(vector<int> &a, int l, int r, int kth) {
        int q = randomPartition(a, l, r);
        if (q == kth) return a[q];
        return q < kth ? quickSelect(a, q + 1, r, kth) : quickSelect(a, l , q - 1, kth);
    }
    int randomPartition(vector<int> &a, int l, int r) {
        int idx = l + rand() % (r - l + 1);
        swap(a[idx], a[l]);
        return partition(a, l, r);
    }
    int partition(vector<int> &a, int l, int r) {
        int val = a[l], x = l, y = r;
        while (x < y) {
            while (x < y && a[y] > val) y--;
            if (x < y) swap(a[x++], a[y]);
            while (x < y && a[x] < val) x++;
            if (x < y) swap(a[x], a[y--]);
        }
        a[x] = val;
        return x;
    }
};

int main() {
    class Solution test; 
    vector<int> nums = {3,2,1,5,6,4};
    cout << test.findKthLargest(nums, 2) << endl;
    return 0;
}
