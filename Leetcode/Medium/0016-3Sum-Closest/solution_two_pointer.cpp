class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = 0x3f3f3f3f, n = nums.size(), ret = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i){
            int l = i + 1, r = n - 1;
            while(l < r){
                int x = nums[i] + nums[l] + nums[r];
                if(abs(x - target) < answer){
                    answer = abs(x - target);
                    ret = x;
                }
                (x < target ? ++l : --r);
            }
        }
        return ret;
    }
};
