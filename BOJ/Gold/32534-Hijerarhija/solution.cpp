#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e5 + 5;
int zeros = 0, indeg[mxn], n;
set<int> g[mxn];
inline void print(){
    cout << (zeros == 1 ? "DA" : "NE") << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        ++indeg[v];
    }
    for(int i = 1; i <= n; ++i){
        if(!indeg[i]){
            ++zeros;
        }
    }
    cin >> q;
    print();
    while(q--){
        int u, v;
        cin >> u >> v;
        if(g[u].find(v) == g[u].end()){
            swap(u, v);
        }
        g[u].erase(v);
        g[v].insert(u);
        if(!--indeg[v]){
            ++zeros;
        }
        if(!indeg[u]++){
            --zeros;
        }
        print();
    }
}
