#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
int a[mxn], dp[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= min(i, k); ++j){
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n - 1];
}
