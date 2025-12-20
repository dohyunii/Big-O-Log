#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define vt vector
#define s second
#define f first
typedef long long int ll;
typedef pair<int, int> pii;
const int mod = 998244353, mxn = 2005;
int a[mxn][mxn];
pii queries[mxn];
ll fact[mxn], ans = 1;
void solve(int x, vt<int> &group){
    if(x == -1){
        return;
    }
    auto [type, j] = queries[x];
    sort(all(group), [&](int i1, int i2){
        return (a[i1][j] < a[i2][j]);
    });
    int idx = 0;
    for(int i = 1; i <= sz(group); ++i){
        if(i == sz(group) || a[group[idx]][j] != a[group[i]][j]){
            int len = i - idx;
            if(type == 1){
                ans = ans * fact[len] % mod;
            }
            else{
                vt<int> nxt;
                for(int k = idx; k < i; ++k){
                    nxt.pb(group[k]);
                }
                solve(x - 1, nxt);
            }
            idx = i;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    fact[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = fact[i - 1] * i % mod;
    }
    for(int i = 0; i < q; ++i){
        cin >> queries[i].f >> queries[i].s;
        --queries[i].s;
    }
    vt<int> initial_group(n);
    iota(all(initial_group), 0);
    solve(q - 1, initial_group);
    cout << ans;
}
