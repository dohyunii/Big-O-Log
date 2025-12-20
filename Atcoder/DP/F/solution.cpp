#include <bits/stdc++.h>
using namespace std;
const int mxn = 3005;
int dp[mxn][mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t, answer;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i] == t[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i && j){
        if(s[i] == t[j]){
            answer.push_back(s[i]);
            --i, --j;
        }
        else{
            (dp[i - 1][j] > dp[i][j - 1] ? --i : --j);
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
}
