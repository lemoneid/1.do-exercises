#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n],c[n],len = 0,k,dp[n];memset(dp,0,sizeof dp);
    for(int i = 0;i < n;i++){
        cin >> c[i];
        auto j = lower_bound(a,a+len,c[i]) - a;
        if(j == len){
            a[len++] = c[i];
            dp[i] = len;
            k = i;
        }else{
            a[j] = c[i];
            dp[i] = j+1;
            if(dp[i] == len) k = i;
        }
        
    }
    cout << " a : ";
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << a[i];
    }
    cout << endl;
    int b[len],l = len;
    b[--len] = c[k];
    for(int i=k;i>=0;--i)
    {
        if(c[i]<c[k] && dp[i]==dp[k]-1)
        {
            b[--len] = c[i];
            k = i;
        }
    }
    for(int i =0;i < l;i++){
        printf("%d",b[i]);
        if(i != l- 1) printf(" ");
    }
}

