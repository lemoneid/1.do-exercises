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
        int *arr = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) arr[i] = nums[i];
        int ans = build(arr, k, nums.size());
        delete[] arr;
        return ans;
    }

    void downUpdate(int *nums, int ind, int size) {
        while ((ind << 1) <= size) {
            int tmp = ind, l = ind << 1, r = ind << 1 | 1;
            if (nums[l] > nums[tmp]) tmp = l;
            if (r <= size && nums[r] > nums[tmp]) tmp = r;
            if (tmp == ind) break;
            swap(nums[tmp], nums[ind]);
            ind = tmp;
        }
        return ;
    }

    int build(int *nums, int k, int size) {
        nums -= 1;
        for (int i = 1; i <= size; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        for (int i = size >> 1; i >= 1; i--) {
            downUpdate(nums, i, size);
        }
        for (int i = 1; i <= size; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        for (int i = 1; i < k; i++) {
            swap(nums[1], nums[size--]);
            downUpdate(nums, 1, size);
        }
        return nums[1];
    }
};

int main() {
    class Solution test; 
    vector<int> nums = {3,2,1,5,6,4};
    cout << test.findKthLargest(nums, 1) << endl;
    return 0;
}
