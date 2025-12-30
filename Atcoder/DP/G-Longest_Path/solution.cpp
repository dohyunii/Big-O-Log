#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
vector<int> g[mxn];
int dp[mxn];
bool vis[mxn];
void dfs(int v){
    vis[v] = true;
    for(auto i : g[v]){
        if(!vis[i]){
            dfs(i);
        }
        dp[v] = max(dp[v], dp[i] + 1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, answer = 0;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
            answer = max(answer, dp[i]);
        }
    }
    cout << answer;
}
