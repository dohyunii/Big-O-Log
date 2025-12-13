#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3 + 5, mod = 1e9 + 7;
char a[mxn][mxn];
int dp[mxn][mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if(i != 1 || j != 1){
                dp[i][j] = ((a[i - 1][j] == '.' ? dp[i - 1][j] : 0) + (a[i][j - 1] == '.' ? dp[i][j - 1] : 0)) % mod;
            }
        }
    }
    cout << dp[n][m];
}
