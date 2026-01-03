#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
const int mxn = 1e5 + 5;
ll dp[mxn];
int answer[mxn], m;
vector<int> g[mxn];
void dfs(int v, int p = -1){
    dp[v] = 1;
    for(auto i : g[v]){
        if(i == p){
            continue;
        }
        dfs(i, v);
        dp[v] = dp[v] * (dp[i] + 1) % m;
    }
}
void calc(int root, int p){
    answer[root] = dp[root];
    vector<int> children;
    for(auto i : g[root]){
        if(i == p){
            continue;
        }
        children.pb(i);
    }
    int k = children.size();
    vector<ll> pref(k), suff(k);
    for(int i = 0; i < k; ++i){
        pref[i] = (dp[children[i]] + 1) * (i ? pref[i - 1] : 1) % m;
    }
    for(int i = k - 1; i >= 0; --i){
        suff[i] = (dp[children[i]] + 1) * (i != k - 1 ? suff[i + 1] : 1) % m;
    }
    for(auto i = 0; i < k; ++i){
        int v = children[i];
        ll temp = dp[v];
        dp[root] = (i ? pref[i - 1] : 1) * (i != k - 1 ? suff[i + 1] : 1) % m * (p != -1 ? dp[p] + 1 : 1) % m;
        dp[v] = dp[v] * (dp[root] + 1) % m;
        calc(v, root);
        dp[root] = answer[root];
        dp[v] = temp;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> m;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    calc(1, -1);
    for(int i = 1; i <= n; ++i){
        cout << answer[i] << '\n';
    }
}