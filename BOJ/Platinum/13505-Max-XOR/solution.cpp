#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
const int mxn = 1e5 + 5;
struct Trie{
    int nxt[2];
    Trie(){
        memset(nxt, -1, sizeof(nxt));
    }
};
string a[mxn];
vector<Trie> trie(1);
void add(string x){
    int v = 0;
    for(auto i : x){
        if(trie[v].nxt[i] == -1){
            trie[v].nxt[i] = sz(trie);
            trie.emplace_back();
        }
        v = trie[v].nxt[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto to_bin = [](int &x){
        string res;
        while(x){
            res.pb(x & 1);
            x >>= 1;
        }
        while(sz(res) < 31){
            res.pb(0);
        }
        reverse(all(res));
        return res;
    };
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        a[i] = to_bin(x);
        add(a[i]);
    }
    int answer = 0;
    for(int i = 0; i < n; ++i){
        int v = 0, res = 0;
        for(auto s : a[i]){
            res <<= 1;
            if(trie[v].nxt[s ^ 1] != -1){
                res |= 1;
                v = trie[v].nxt[s ^ 1];
            }
            else{
                v = trie[v].nxt[s];
            }
        }
        answer = max(answer, res);
    }
    cout << answer;
}