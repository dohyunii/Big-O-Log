#include <bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 5;
bool vis[mxn];
int lst[mxn / 3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(lst, -1, sizeof(lst));
    int n;
    string s;
    cin >> n >> s;
    if(n % 3){
        cout << "mix";
        return 0;
    }
    int k = n / 3;
    for(auto t : { 'H', 'O', 'H' }){
        int idx = 0;
        for(int i = 0; i < n; ++i){
            if(idx < k && !vis[i] && s[i] == t && i > lst[idx]){
                lst[idx++] = i;
                vis[i] = true;
            }
        }
        if(idx != k){
            cout << "mix";
            return 0;
        }
    }
    cout << "pure";
}
