class Solution {
public:
    static const int mxn = 1e3 + 5;
    static const long long int linf = 0x3f3f3f3f3f3f3f3f;
    long long int dp[mxn >> 1][3], temp[mxn >> 1][3];
    long long maximumProfit(vector<int>& prices, int K) {
        const int n = prices.size();
        for(int i = 0; i <= K; ++i){
            temp[i][0] = 0;
            temp[i][1] = temp[i][2] = -linf;
        }
        for(int i = n - 1; i >= 0; --i){
            for(int k = 0; k <= K; ++k){
                dp[k][0] = max({ temp[k][0], temp[k][1] - prices[i], temp[k][2] + prices[i] });
                dp[k][1] = temp[k][1];
                dp[k][2] = temp[k][2];
                if(k){
                    dp[k][1] = max(temp[k][1], temp[k - 1][0] + prices[i]);
                    dp[k][2] = max(temp[k][2], temp[k - 1][0] - prices[i]);
                }
            }
            copy(&dp[0][0], &dp[0][0]+3*(K+1), &temp[0][0]);
        }
        return dp[K][0];
    }
};
