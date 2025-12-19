class Solution {
public:
    static const int mod = 1e9 + 7, p = 31, mxn = 1e3 + 5;
    long long int h[mxn], pw[mxn], rh[mxn];
    int n;
    inline bool comp(int l1, int r1, int l2, int r2){
        return ((h[r1] - h[l1 - 1] + mod) % mod * pw[n - r2] % mod == (rh[l2] - rh[r2 + 1] + mod) % mod * pw[l1 - 1] % mod);
    }
    string longestPalindrome(string s) {
        n = s.size();
        s = '#' + s;
        pw[0] = 1;
        for(int i = 1; i < mxn; ++i){
            pw[i] = pw[i - 1] * p % mod;
        }
        for(int i = 1; i <= n; ++i){
            h[i] = (h[i - 1] + (s[i] - 'a' + 1) * pw[i]) % mod;
        }
        for(int i = n; i >= 1; --i){
            rh[i] = (rh[i + 1] + (s[i] - 'a' + 1) * pw[n - i + 1]) % mod;
        }
        int mx = 0, lans = 1;
        for(int i = 1; i <= n; ++i){
            int l = 1, r = min(n - i, i), ans = 0;
            while(l <= r){
                int mid = l + r >> 1;
                if(comp(i - mid + 1, i, i + 1, i + mid)){
                    ans = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            if(mx < ans * 2){
                mx = ans * 2;
                lans = i - ans + 1;
            }
            l = 1, r = min(n - i, i - 1), ans = 0;
            while(l <= r){
                int mid = l + r >> 1;
                if(comp(i - mid, i - 1, i + 1, i + mid)){
                    l = mid + 1;
                    ans = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            if(mx < ans * 2 + 1){
                mx = ans * 2 + 1;
                lans = i - ans;
            }
        }
        return s.substr(lans, mx);
    }
};
