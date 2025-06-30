class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = 0;
            bool hasDiff1 = false;

            for (int j = 0; j < n; j++) {
                int diff = nums[j] - nums[i];
                if (diff == 0 || diff == 1) {
                    count++;
                    if (diff == 1) hasDiff1 = true;
                }
            }

            if (hasDiff1) {
                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};
