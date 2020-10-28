/*************************************************************************
	> File Name: cd-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月13日 星期日 15时36分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, temp;
    vector <int> arr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int mmax, mmin;
        mmax =  mmin = arr[i];
        map <int, int> mmap;
        for (int j = i; j < arr.size(); ++j) {
            if (mmap.count(arr[j])) {
                break;
            }
            mmax = max(mmax, arr[j]);
            mmin = min(mmin, arr[j]);
            mmap.insert(arr[j], 1);
            if (mmax - mmin == j - i) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
