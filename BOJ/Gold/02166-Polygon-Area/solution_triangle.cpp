#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto calc = [](const pair<int, int> &p, const pair<int, int> &x, const pair<int, int> &y){
        return 1LL * (x.first - p.first) * (y.second - p.second) - 1LL * (y.first - p.first) * (x.second - p.second);
    };
    int n;
    long long area = 0;
    cin >> n;
    pair<int, int> prev, piv;
    cin >> piv.first >> piv.second;
    prev = piv;
    for(int i = 1; i < n; ++i){
        pair<int, int> curr;
        cin >> curr.first >> curr.second;
        area += calc(piv, prev, curr);
        prev = curr;
    }
    cout << (abs(area) >> 1) << '.' << (area & 1 ? '5' : '0');
}