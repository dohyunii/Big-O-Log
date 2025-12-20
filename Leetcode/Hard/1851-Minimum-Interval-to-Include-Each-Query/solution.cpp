class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        unordered_map<int, int> answer;
        sort(a.begin(), a.end());
        vector<int> temp = queries, ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        sort(temp.begin(), temp.end());
        int idx = 0;
        const int n = (int)a.size();
        for(auto i : temp){
            while(idx < n && a[idx][0] <= i){
                q.push({ a[idx][1] - a[idx][0] + 1, a[idx++][1] });
            }
            while(!q.empty() && q.top().second < i){
                q.pop();
            }
            answer[i] = (q.empty() ? -1 : q.top().first);
        }
        for(auto i : queries){
            ret.push_back(answer[i]);
        }
        return ret;
    }
};
