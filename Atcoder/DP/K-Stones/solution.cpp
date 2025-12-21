#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1);
    for(auto &i : a){
        cin >> i;
    }
    for(int i = 1; i <= k; ++i){
        for(auto j : a){
            if(j > i){
                break;
            }
            dp[i] |= !dp[i - j];
        }
    }
    cout << (dp[k] ? "First" : "Second");
}