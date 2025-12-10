#include <bits/stdc++.h>
using namespace std;
const int mxv = 1e3 + 5, mxn = 105;
long long int dp[mxn * mxv];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n, m;
    cin >> n >> m;
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        int w, v;
        cin >> w >> v;
        for(int j = mxn * mxv - 1; j >= v; --j){
            dp[j] = min(dp[j - v] + w, dp[j]);
        }
    }
    for(int i = mxn * mxv - 1; i >= 0; --i){
        if(dp[i] <= m){
            cout << i;
            return 0;
        }
    }
}
