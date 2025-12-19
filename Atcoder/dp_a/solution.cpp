#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
int a[mxn], dp[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for(int i = 2; i < n; ++i){
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1];
}
