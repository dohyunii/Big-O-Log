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
typedef ModInt<1000000007> mint;
const int mxn = 1e4 + 5, mxd = 105;
string x, y;
int d, n;
mint dp[mxn][2][2][mxd];
mint solve(int pos, bool fl, bool fr, int c){
    if(pos == n){
        return !c;
    }
    if(dp[pos][fl][fr][c].get() != -1){
        return dp[pos][fl][fr][c];
    }
    dp[pos][fl][fr][c] = 0;
    for(int i = (fl ? 0 : y[pos] - '0'); i <= (fr ? 9 : x[pos] - '0'); ++i){
        dp[pos][fl][fr][c] += solve(pos + 1, fl | (i > y[pos] - '0'), fr | (i < x[pos] - '0'), (c + i) % d);
    }
    return dp[pos][fl][fr][c];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> x >> d;
    while((int)y.size() + 1 < (int)x.size()){
        y.push_back('0');
    }
    y.push_back('1');
    n = (int)x.size();
    cout << solve(0, false, false, 0);
}