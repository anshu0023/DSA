class Solution {
public:
    string clearStars(string s) {
        vector<char> stk;
        multiset<char> ms;

        for (char c : s) {
            if (c != '*') {
                stk.push_back(c);
                ms.insert(c);
            } else {
                if (ms.empty()) continue;

                char smallest = *ms.begin();
                for (int i = (int)stk.size() - 1; i >= 0; --i) {
                    if (stk[i] == smallest) {
                        ms.erase(ms.find(smallest));
                        stk.erase(stk.begin() + i);
                        break;
                    }
                }
            }
        }

        return string(stk.begin(), stk.end());
    }
};