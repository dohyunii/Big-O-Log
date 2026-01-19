#include <bits/stdc++.h>
using namespace std;
template <int MOD> struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(long long p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<1000000007> mint;
const int mxn = 2e5 + 5;
set<int> g[mxn];
vector<tuple<int, int, int>> tri;
map<pair<int, int>, vector<int>> gr;
vector<int> edges[mxn];
mint dp[mxn], answer = 0;
void dfs(int v, int p){
    dp[v] = 1;
    for(auto i : edges[v]){
        if(i == p){
            continue;
        }
        dfs(i, v);
        dp[v] *= dp[i] + 1;
    }
    answer += dp[v];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 3; ++i){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i = 1; i <= n; ++i){
        g[i].insert(i % n + 1);
        g[i % n + 1].insert(i);
    }
    for(int u = 1; u <= n; ++u){
        for(auto i = g[u].begin(); i != prev(g[u].end()); ++i){
            int v = *i, w = *next(i);
            if(v < u || g[v].find(w) == g[v].end()){
                continue;
            }
            tri.push_back(make_tuple(u, v, w));
        }
    }
    for(int i = 1; i <= (int)tri.size(); ++i){
        auto [u, v, w] = tri[i - 1];
        gr[make_pair(u, v)].push_back(i);
        gr[make_pair(u, w)].push_back(i);
        gr[make_pair(v, w)].push_back(i);
    }
    for(auto i : gr){
        if((int)i.second.size() != 2){
            continue;
        }
        edges[i.second[0]].push_back(i.second[1]);
        edges[i.second[1]].push_back(i.second[0]);
    }
    dfs(1, -1);
    cout << answer;
}