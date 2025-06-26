class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include nums[i]
        curr.push_back(nums[i]);
        solve(i + 1, nums, curr, ans);
        curr.pop_back();

        // Skip all duplicates of nums[i]
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) j++;

        // Exclude nums[i] and all its duplicates
        solve(j, nums, curr, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important for duplicate handling
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans);
        return ans;
    }
};
