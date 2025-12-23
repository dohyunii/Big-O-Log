#include <bits/stdc++.h>
using namespace std;
const int mxn = 405;
long long int dp[mxn][mxn], pref[mxn];
const long long int linf = 0x3f3f3f3f3f3f3f3f;
long long int solve(int l, int r){
    if(l == r){
        return 0;
    }
    if(dp[l][r] != linf){
        return dp[l][r];
    }
    for(int x = l; x < r; ++x){
        dp[l][r] = min(dp[l][r], solve(l, x) + solve(x + 1, r) + pref[r] - pref[l - 1]);
    }
    return dp[l][r];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> dp[i][i];
        pref[i] = pref[i - 1] + dp[i][i];
    }
    cout << solve(1, n);
}