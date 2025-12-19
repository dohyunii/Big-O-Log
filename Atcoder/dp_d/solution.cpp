#include <bits/stdc++.h>
using namespace std;
const int mxw = 1e5 + 5, mxn = 105;
long long int dp[mxw];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int w, v;
        cin >> w >> v;
        for(int j = m; j >= w; --j){
            dp[j] = max(dp[j - w] + v, dp[j]);
        }
    }
    cout << *max_element(dp, dp + m + 1);
}
