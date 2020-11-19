/*************************************************************************
	> File Name: cd-181-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 15时41分57秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MOD 1000000007
#define MAX_N 10000
int n;
long long f[MAX_N + 5];

int main() {
  f[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * (4 * i - 2) / (i + 1), f[i] %= MOD;
  cout << f[n] << endl;
  return 0;
}

