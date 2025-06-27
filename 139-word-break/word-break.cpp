class Solution {
public:
    bool solve(string& s, int index, unordered_set<string>& dict, unordered_map<int, bool>& memo) {
        if (index == s.size()) return true;
        if (memo.find(index) != memo.end()) return memo[index];

        for (int end = index + 1; end <= s.size(); ++end) {
            if (dict.count(s.substr(index, end - index)) && solve(s, end, dict, memo)) {
                return memo[index] = true;
            }
        }

        return memo[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return solve(s, 0, dict, memo);
    }
};
