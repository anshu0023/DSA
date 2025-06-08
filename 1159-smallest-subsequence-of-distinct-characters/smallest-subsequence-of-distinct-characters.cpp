class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool>inStack(26, false);
        int n = s.size();

        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;

        string result = "";
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (inStack[c - 'a']) continue;

            while (!result.empty() && c < result.back() && last[result.back() - 'a'] > i) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inStack[c - 'a'] = true;
        }

        return result;
    }
};