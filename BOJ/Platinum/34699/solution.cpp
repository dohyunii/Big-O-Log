#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
const long long int linf = 0x3f3f3f3f3f3f3f3f;
long long int dp[mxn][2][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n, c1, c2;
    string s, t;
    cin >> n >> s >> t >> c1 >> c2;
    for(int i = 0; i < n; ++i){
        s[i] -= '0';
        t[i] -= '0';
    }
    dp[n][0][0] = 0;
    for(int i = n - 1; i >= 0; --i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                if((s[i] ^ j) != (t[i] ^ k)){
                    dp[i][j][k] = linf;
                }
                else if(s[i] ^ j){
                    dp[i][j][k] = min({ dp[i + 1][j][k], dp[i + 1][j][k ^ 1] + c1, dp[i + 1][j ^ 1][k] + c1, dp[i + 1][j ^ 1][k ^ 1] + c1 * 2 });
                }
                else{
                    dp[i][j][k] = min({ dp[i + 1][j][k], dp[i + 1][j][k ^ 1] + c1, dp[i + 1][j ^ 1][k] + c1, dp[i + 1][j ^ 1][k ^ 1] + c1 * 2 }) + c2;
                }
            }
        }
    }
    cout << min({ dp[0][0][0], dp[0][1][1], dp[0][1][0], dp[0][0][1] });
}
