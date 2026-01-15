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
const int mxn = 3e3 + 5, mod = 1e9 + 7, mxN = 2e5 + 5;
typedef ModInt<mod> mint;
pair<int, int> a[mxn];
mint dp[mxn], fact[mxN], inv[mxN];
mint nCk(int n, int k){
    return fact[n] * inv[k] * inv[n - k];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < mxN; ++i){
        fact[i] = fact[i - 1] * i;
    }
    inv[mxN - 1] = fact[mxN - 1].pow(mod - 2);
    for(int i = mxN - 2; i >= 0; --i){
        inv[i] = inv[i + 1] * (i + 1);
    }
    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    a[n] = make_pair(h, w);
    for(int i = 0; i <= n; ++i){
        dp[i] = nCk(a[i].first + a[i].second - 2, a[i].first - 1);
        for(int j = 0; j < i; ++j){
            if(a[j].second > a[i].second){
                continue;
            }
            dp[i] -= dp[j] * nCk(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first);
        }
    }
    cout << dp[n];
}