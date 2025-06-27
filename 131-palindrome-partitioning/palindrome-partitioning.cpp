class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(int start, int end, string& s, vector<string>& path, vector<vector<string>>& res) {
        if (end == s.size()) return;

        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            if (end + 1 == s.size()) {
                res.push_back(path);
            } else {
                solve(end + 1, end + 1, s, path, res);
            }
            path.pop_back();
        }

        solve(start, end + 1, s, path, res);
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0, 0, s, path, res);
        return res;
    }
};
