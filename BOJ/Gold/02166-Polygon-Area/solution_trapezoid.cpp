#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto calc = [](const pair<int, int> &x, const pair<int, int> &y){
        return 1LL * (y.first - x.first) * (y.second + x.second);
    };
    int n;
    long long area = 0;
    cin >> n;
    pair<int, int> prev, fst;
    cin >> fst.first >> fst.second;
    prev = fst;
    for(int i = 1; i < n; ++i){
        pair<int, int> curr;
        cin >> curr.first >> curr.second;
        area += calc(prev, curr);
        prev = curr;
    }
    area += calc(prev, fst);
    cout << (abs(area) >> 1) << '.' << (area & 1 ? '5' : '0');
}