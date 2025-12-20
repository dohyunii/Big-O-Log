#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
int st[18][mxn], a[mxn], cnt[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> st[0][i];
    }
    for(int i = 1; i < 18; ++i){
        for(int v = 1; v <= n; ++v){
            st[i][v] = st[i - 1][st[i - 1][v]];
        }
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    auto ok = [&](const int &x){
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i){
            int v = a[i], temp = x;
            for(int j = 17; j >= 0; --j){
                if(temp >= (1 << j)){
                    temp -= (1 << j);
                    v = st[j][v];
                }
            }
            if(++cnt[v] >= k){
                return true;
            }
        }
        return false;
    };
    int l = 0, r = n, ans = -2;
    while(l <= r){
        int mid = l + r >> 1;
        if(ok(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans + 1;
}
