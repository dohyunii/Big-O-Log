#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
int lst[mxn / 6];
bool vis[mxn];
const string need = "sogang";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    auto ok = [&](const int &x){
        memset(lst, -1, x << 2);
        memset(vis, false, n);
        for(auto i : need){
            int idx = 0;
            for(int j = 0; j < n; ++j){
                if(idx < x && s[j] == i && !vis[j] && lst[idx] < j){
                    lst[idx++] = j;
                    vis[j] = true;
                }
            }
            if(idx < x){
                return false;
            }
        }
        return true;
    };
    int l = 0, r = n / 6, ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(ok(mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
}
