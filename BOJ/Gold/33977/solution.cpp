#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int leaf = 1;
    for(int i = sqrt(k); i > 1; --i){
        if(k % i == 0){
            leaf = i;
            break;
        }
    }
    cout << leaf + k / leaf << '\n';
    for(int i = leaf - 1; i > 0; --i){
        cout << i << ' ' << i * 2 << '\n' << i << ' ' << i * 2 + 1 << '\n';
    }
    for(int i = 0; i < k / leaf - leaf + 1; ++i){
        cout << 2 * leaf - 1 + i << ' ' << 2 * leaf + i << '\n';
    }
}
