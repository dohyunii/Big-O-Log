class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = (int)nums.size(), answer = 0;
        for(int i = 0; i < n; ++i){
            answer |= nums[i];
        }
        return (answer << n - 1);
    }
};
