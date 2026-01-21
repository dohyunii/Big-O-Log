#include <bits/stdc++.h>
using namespace std;
const int mxn = 505;
pair<int, int> a[mxn];
long long dp[mxn][mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        dp[i][i] = 0;
    }
    for(int gap = 2; gap <= n; ++gap){
        for(int l = 0; l + gap <= n; ++l){
            int r = l + gap - 1;
            for(int k = l; k < r; ++k){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + 1LL * a[l].first * a[k].second * a[r].second);
            }
        }
    }
    cout << dp[0][n - 1];
}