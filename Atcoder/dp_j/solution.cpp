#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int mxn = 305;
int cnt[4], n;
ld dp[mxn][mxn][mxn];
ld dfs(int i, int j, int k){
    if(min({ i, j, k }) < 0 || !(i | j | k)){
        return .0L;
    }
    if(dp[i][j][k]){
        return dp[i][j][k];
    }
    return dp[i][j][k] = (dfs(i - 1, j, k) * i + dfs(i + 1, j - 1, k) * j + dfs(i, j + 1, k - 1) * k + n) / (i + j + k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++cnt[x];
    }
    cout << fixed << setprecision(9) << dfs(cnt[1], cnt[2], cnt[3]);
}
