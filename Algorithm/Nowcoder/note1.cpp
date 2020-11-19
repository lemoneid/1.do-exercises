#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin>>n;
    vector<long>oil(n);
    vector<long>cost(n);
    for(long i=0;i<n;++i) cin>>oil[i];
    for(long i=0;i<n;++i) cin>>cost[i];
    // 每个站能获得的纯能
    for(long i=0;i<n;++i) oil[i]-=cost[i];
    vector<int>ans(n,-1);
    long start = 0;
    long end = 1;
    long rest = oil[0];
    while(start!=end)
    {
        if(rest>=0)  // 向右扩，看是否能到下一个站
        {
            rest += oil[end];
            end = (end+1)%n;
        }
        else  // 向左扩，看上一个站有没有可能补充上现在相差的油量
        {
            start = (start-1+n)%n;
            rest += oil[start];
        }
    }
     if (rest >= 0) {
        ans[start] = 1;
        long cur = (start - 1 + n ) % n;
        rest = oil[cur];
         while (cur != start)
        {
            // 向左找，看上一站能否到达可行点
            if(rest>=0)   // 可达
            {
                ans[cur]=1;
                cur = (cur-1+n)%n; 
                rest = oil[cur]; // 油量置成上一站的
            }
            else  // 不可达
            {
                ans[cur] = 0;
                cur = (cur-1+n)%n;  // 也往左找，寻求可能补充油量的站出现
                rest += oil[cur];
            }
        }

        //} while (cur != start);
    }
    /*
    if(rest>=0) // 找到一个可行出发点能绕行一周
    {
        long cur = start;
        rest = oil[start];
        do
        {
            // 向左找，看上一站能否到达可行点
            if(rest>=0)   // 可达
            {
                ans[cur]=1;
                cur = (cur-1+n)%n; 
                rest = oil[cur]; // 油量置成上一站的
            }
            else  // 不可达
            {
                ans[cur] = 0;
                cur = (cur-1+n)%n;  // 也往左找，寻求可能补充油量的站出现
                rest += oil[cur];
            }

        } while (cur != start);
    }
    */
    for (int i = 0; i < n; ++i) {
        cout << (ans[i] > 0 ? ans[i] : 0) << " ";
    }
    return 0;
}
