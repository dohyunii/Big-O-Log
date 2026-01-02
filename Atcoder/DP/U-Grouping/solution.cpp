#include <bits/stdc++.h>
using namespace std;
const int mxn = 16;
int a[mxn][mxn];
long long int cost[1 << mxn], dp[1 << mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for(int mask = 1; mask < (1 << n); ++mask){
        for(int i = 1; i < n; ++i){
            if(mask >> i & 1 ^ 1){
                continue;
            }
            for(int j = 0; j < i; ++j){
                if(mask >> j & 1){
                    cost[mask] += a[i][j];
                }
            }
        }
    }
    for(int mask = 1; mask < (1 << n); ++mask){
        for(int msk = mask; msk > 0; msk = (msk - 1) & mask){
            dp[mask] = max(dp[mask], dp[mask - msk] + cost[msk]);
        }
    }
    cout << dp[(1 << n) - 1];
}