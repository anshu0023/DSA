class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) return 0;
        
        int n = nums.size();
        int mini = INT_MAX;
        set<int> s;

        for (int i = x; i < n; ++i) {
            s.insert(nums[i - x]); 
            
            auto it = s.lower_bound(nums[i]); 
            if (it != s.end()) {
                mini = min(mini, abs(*it - nums[i]));
            }
            if (it != s.begin()) {
                --it;
                mini = min(mini, abs(*it - nums[i]));
            }
        }

        return mini;
    }
};
