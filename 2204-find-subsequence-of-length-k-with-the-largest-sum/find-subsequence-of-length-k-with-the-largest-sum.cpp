class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;

        for (int i = 0; i < nums.size(); ++i) {
            indexed.push_back({nums[i], i});
        }

        sort(indexed.begin(), indexed.end(), greater<pair<int, int>>());

        vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(indexed[i].second);
        }

        sort(indices.begin(), indices.end());

        vector<int> result;
        for (int i : indices) {
            result.push_back(nums[i]);
        }

        return result;
    }
};
