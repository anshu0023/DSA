class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& combo, vector<vector<int>>& res) {
        if (k == 0 && n == 0) {
            res.push_back(combo);
            return;
        }
        if (k == 0 || n < 0) return;

        if (start > 9) return;

        // Include current number
        combo.push_back(start);
        backtrack(start + 1, k - 1, n - start, combo, res);
        combo.pop_back();

        // Exclude current number
        backtrack(start + 1, k, n, combo, res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combo;
        backtrack(1, k, n, combo, res);
        return res;
    }
};
