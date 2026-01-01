#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <int MOD> struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
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
const int mod = 1e9 + 7, mxn = 3e3 + 5;
typedef ModInt<mod> mint;
mint dp[mxn], pref[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            pref[j] = pref[j - 1] + dp[j];
        }
        memset(dp, 0, sizeof(dp));
        if(s[i - 1] == '>'){
            for(int j = 1; j <= i; ++j){
                dp[j] += pref[i - 1] - pref[j - 1];
            }
        }
        else{
            for(int j = 1; j <= i; ++j){
                dp[j] += pref[j - 1];
            }
        }
    }
    mint answer = 0;
    for(int i = 1; i <= n; ++i){
        answer += dp[i];
    }
    cout << answer;
}