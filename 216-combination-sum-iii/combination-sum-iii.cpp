class Solution {
public:
    void helper(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            int sum = 0;
            for (int x : current) sum += x;
            if (sum == n) result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            helper(i + 1, k, n, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        helper(1, k, n, current, result);
        return result;
    }
};
