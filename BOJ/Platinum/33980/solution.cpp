#include <bits/stdc++.h>
using namespace std;
int n;
int solve(string s, string t){
    int answer = 0, mn = 1, curr = 0;
    auto update = [](string &s, const bool type, int &answer){
        char fc = (type ? 'R' : 'U'), ec = (type ? 'U' : 'R');
        int f = s.rfind(fc), e = s.find(ec);
        if(s[0] != fc || s[n - 1] != ec){
            ++answer;
            swap(s[f], s[e]);
        }
    };
    update(s, false, answer);
    update(t, true, answer);
    for(int i = 0; i < n - 1; ++i){
        curr += (s[i] == 'U') - (t[i] == 'U');
        mn = min(mn, curr);
    }
    answer += 1 - mn;
    return answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> n;
    n <<= 1;
    cin >> s >> t;
    // make first string U...R form, and make second string R...U form
    cout << min(solve(s, t), solve(t, s));
}
