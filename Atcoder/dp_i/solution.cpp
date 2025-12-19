#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e3 + 5;
long double dp[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        long double p;
        cin >> p;
        for(int j = i; j >= 0; --j){
          dp[j] = (j ? dp[j - 1] * p : .0L) + (i > j ? dp[j] * (1.0L - p) : .0L);  
        }
    }
    cout << fixed << setprecision(9) << accumulate(dp + n / 2 + 1, dp + n + 1, .0L);
}
