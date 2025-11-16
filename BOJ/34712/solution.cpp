#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5;
typedef long long int ll;
ll get(ll x){
    cout << "? " << x << endl;
    cin >> x;
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll atmxn = get(mxn), slope = n;
    int l = 1, r = mxn, ans = mxn;
    while(l <= r){
        ll mid = l + r >> 1;
        if(slope * (mxn - mid) != atmxn - get(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }
    cout << "! " << ans << endl;
}
