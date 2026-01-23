#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
vector<int> g[mxn];
int up[19][mxn];
void dfs(int v, int p){
    up[0][v] = p;
    for(int i = 1; i < 19; ++i){
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for(auto i : g[v]){
        if(i == p){
            continue;
        }
        dfs(i, v);
    }
}
int solve(int v, int k){
    for(int i = 18; i >= 0; --i){
        if(k >= (1 << i)){
            k -= (1 << i);
            v = up[i][v];
            if(!v){
                break;
            }
        }
    }
    return (v ? v : -1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 2, v; i <= n; ++i){
        cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    dfs(1, 0);
    while(q--){
        int v, k;
        cin >> v >> k;
        cout << solve(v, k) << '\n';
    }
}