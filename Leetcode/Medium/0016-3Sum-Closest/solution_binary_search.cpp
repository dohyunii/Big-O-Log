class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = 0x3f3f3f3f, n = nums.size(), ret = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i){
            for(int j = i + 1; j < n - 1; ++j){
                int x = nums[i] + nums[j];
                int l = j + 1, r = n - 1, ans = l;
                while(l <= r){
                    int mid = l + r >> 1;
                    if(x + nums[mid] < target){
                        ans = mid;
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                if(answer > abs(target - nums[ans] - x)){
                    answer = abs(target - nums[ans] - x);
                    ret = nums[ans] + x;
                }
                if(ans + 1 < n && abs(nums[ans + 1] + x - target) < answer){
                    answer = abs(nums[ans + 1] + x - target);
                    ret = nums[ans + 1] + x;
                }
            }
        }
        return ret;
    }
};
