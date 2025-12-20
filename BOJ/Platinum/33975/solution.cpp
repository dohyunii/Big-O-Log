#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
int a[mxn], b[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, curr = 0;
    long long int answer1 = 0, answer2 = 0;
    cin >> n;
    n <<= 1;
    for(int i = 0; i < n; ++i){
        char ch;
        cin >> ch;
        a[i] = (ch == 'R') + (i ? a[i - 1] : 0);
    }
    for(int i = 0; i < n - 1; ++i){
        char ch;
        cin >> ch;
        curr += (ch == 'R');
        answer1 += max(0, 1 + curr - a[i]);
        answer2 += max(0, 1 + a[i] - curr);
    }
    cout << min(answer1, answer2) << '\n';
}
