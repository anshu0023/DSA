class Solution {
public:
    vector<string> res;
    string s;
    int target;

    void dfs(int idx, long currVal, long prevVal, string expr) {
        if (idx == s.size()) {
            if (currVal == target)
                res.push_back(expr);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (i > idx && s[idx] == '0') break;
            string part = s.substr(idx, i - idx + 1);
            long val = stol(part);

            if (idx == 0) {
                dfs(i + 1, val, val, part);
            } else {
                dfs(i + 1, currVal + val, val, expr + "+" + part);
                dfs(i + 1, currVal - val, -val, expr + "-" + part);
                dfs(i + 1, currVal - prevVal + prevVal * val, prevVal * val, expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        dfs(0, 0, 0, "");
        return res;
    }
};
