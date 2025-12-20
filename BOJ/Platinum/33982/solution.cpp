#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define vt vector
#define f first
#define s second
typedef long long int ll;
const int mxn = 1e5 + 5;
int p[mxn], cnt[mxn], ans[mxn];
bool stopped[mxn]; 
vt<pair<int, int>> g[mxn];
vt<int> tr[mxn];
ll dead[mxn];
string answers[] = {"YES", "NO: Duplicate Visit", "NO: Edge Absence", "NO: Collision"};
struct Event{
    ll t;
    int v, i, type; // 0: ok, 1: duplicate, 2: edge absence
    bool stuck;
    bool operator>(const Event &o) const{
        return ((t != o.t) ? (t > o.t) : (v > o.v));
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dead, 0x3f, sizeof(dead));    
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ v, w });
        g[v].pb({ u, w });
    }
    for(int i = 1; i <= n; ++i){
        sort(all(g[i]));
    }
    priority_queue<Event, vector<Event>, greater<Event>> events;
    for(int i = 0; i < t; ++i){
        int k;
        ll l;
        cin >> k >> l;
        tr[i].resize(k);
        for(int &x : tr[i]){
            cin >> x;
        }
        unordered_set<int> vis;
        for(int j = 0; j < k; ++j){
            int v = tr[i][j], type = 0;
            bool is_stuck = false;
            if(vis.count(v)){
                type = 1; 
            }
            vis.insert(v);
            ll next_cost = 0;
            if(j < k - 1){
                auto it = lower_bound(all(g[v]), make_pair(tr[i][j + 1], 0));
                if(it == g[v].end() || it->f != tr[i][j + 1]){
                    is_stuck = true;
                    if(!type){
                        type = 2;
                    }
                }
                else{
                    next_cost = it->s;
                }
            }
            events.push({ l, v, i, type, is_stuck });
            if(is_stuck){
                break;
            }
            l += next_cost;
        }
    }
    while(!events.empty()){
        vt<Event> b;
        b.pb(events.top());
        events.pop();
        while(!events.empty() && events.top().t == b[0].t && events.top().v == b[0].v){
            b.pb(events.top());
            events.pop();
        }
        ll now = b[0].t;
        int v = b[0].v, incoming_count = 0;
        for(auto &e : b){
            incoming_count += !stopped[e.i];
        }
        bool is_jammed = (dead[v] <= now), collision = (incoming_count > 1 - is_jammed); 
        if(collision){
            dead[v] = min(dead[v], now);
        }
        for(auto& e : b){
            if(stopped[e.i]){
                continue;
            }
            int current_err = 0;
            bool will_stop = false;
            if(e.stuck || collision) {
                will_stop = true;
                dead[v] = min(dead[v], now);
            }
            if(e.type == 1){
                current_err = 1;
            }
            else if(collision){
                current_err = 3;
            }
            else if(e.type == 2){
                current_err = 2;
            }
            if(!ans[e.i] && current_err){
                ans[e.i] = current_err;
            }
            if(will_stop){
                stopped[e.i] = true;
            }
        }
    }
    int valid_count = 0;
    for(int i = 0; i < t; ++i){
        valid_count += !ans[i];
    }
    cout << valid_count << '\n';
    for(int i = 0; i < t; ++i) {
        cout << answers[ans[i]] << '\n';
        if(!ans[i]){
            for(int x : tr[i]){
                ++cnt[x];
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(cnt[i] < p[i]){
            cout << "unfilled";
            return 0;
        }
    }
    cout << "filled";
}
