#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define vt vector
#define s second
#define f first
void solve(){
    ll n;
    int s, c;
    cin >> n >> s >> c;
    if(s == c){
        if(n % s || ((n / s + 1) & (n / s))){
            cout << "0\n";
            return;
        }
        n = n / s + 1;
        int m = 0;
        for(ll x = 1; x != n; x <<= 1){
            ++m;
        }
        if(m < 4){
            cout << "0\n";
            return;
        }
        vt<vt<ll>> dp(m + 1, vt<ll>(8));
        /*
        0    1    2    3    4    5    6    7
        sss, ssc, scs, scc, css, csc, ccs, ccc
        */
        for(int i = 0; i < 8; ++i){
            dp[3][i] = 1;
        }
        for(int i = 4; i <= m; ++i){
            dp[i][0] = dp[i][1] = dp[i - 1][4] + dp[i - 1][0];
            dp[i][2] = dp[i][3] = dp[i - 1][1] + dp[i - 1][5];
            dp[i][4] = dp[i - 1][2] + dp[i - 1][6];
            dp[i][5] = dp[i - 1][6];
            dp[i][6] = dp[i][7] = dp[i - 1][3] + dp[i - 1][7];
        }
        cout << (1LL << m) - accumulate(all(dp[m]), 0LL) << '\n';
    }
    else{
        int answer = 0;
        for(int m = 0; m < 40; ++m){
            if(!((n - ((1LL << m) - 1) * s) % (c - s))){
                ll p = (n - ((1LL << m) - 1) * s) / (c - s);
                if(p < 0 || p >= (1LL << m)){
                    continue;
                }
                string st(m, 's');
                for(int i = m - 1; i >= 0 && p; --i, p >>= 1){
                    if(p & 1){
                        st[i] = 'c';
                    }
                }
                answer += (st.find("scsc") != string::npos);
            }
        }
        cout << answer << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
