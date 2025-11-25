#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define pb push_back
#define vt vector
typedef long long ll;
const int mxn = 3e3 + 5, p = 31, mod = 1e9 + 7;
ll h[mxn], pw[mxn];
ll get_hash(int l, int r) {
    return (h[r + 1] - h[l] * pw[r - l + 1] % mod + mod) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    pw[0] = 1;
    for(int i = 0; i < n; ++i){
        pw[i + 1] = (pw[i] * p) % mod;
        h[i + 1] = (h[i] * p + (s[i] - 'a' + 1)) % mod;
    }
    for(int k = 1; k <= n; ++k){
        int answer = 0;
        for(int r = 0; r < k; ++r){
            vt<int> pos;
            for(int i = r; i + k <= n; i += k){
                pos.pb(i);
            }
            int cnt = 0;
            for(int i = 0; i < sz(pos); ++i){
                answer++;
                cnt ++;
                int left = i - 1, right = i + 1;
                while(left >= 0 && right < sz(pos)){
                    if(get_hash(pos[left], pos[left] + k - 1) != get_hash(pos[right], pos[right] + k - 1)){
                        break;
                    }
                    ++answer, --left, ++right;
                    ++cnt;
                }
            }
            cnt = 0;
            for(int i = 0; i < sz(pos) - 1; ++i){
                int left = i, right = i + 1;
                while(left >= 0 && right < sz(pos)){
                    if(get_hash(pos[left], pos[left] + k - 1) != get_hash(pos[right], pos[right] + k - 1)){
                        break;
                    }
                    ++answer, --left, ++right;
                }
            }
        }
        cout << answer << "\n";
    }
}
