#include <bits/stdc++.h>
using namespace std;
const int mxn = 405;
long long int dp[mxn][mxn], pref[mxn];
const long long int linf = 0x3f3f3f3f3f3f3f3f;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        dp[i][i] = 0;
        pref[i] = pref[i - 1] + x;
    }
    for(int len = 2; len <= n; ++len){
        for(int l = 1; l + len - 1 <= n; ++l){
            int r = l + len - 1;
            for(int x = l; x < r; ++x){
                dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r] + pref[r] - pref[l - 1]);
            }
        }
    }
    cout << dp[1][n];
}