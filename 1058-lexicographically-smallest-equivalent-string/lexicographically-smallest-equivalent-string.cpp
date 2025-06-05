class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> groups;

       for (int i = 0; i < s1.length(); ++i) {
            char a = s1[i];
            char b = s2[i];
            int groupA = -1, groupB = -1;

            for (int j = 0; j < groups.size(); ++j) {
                if (groups[j].count(a)) groupA = j;
                if (groups[j].count(b)) groupB = j;
            }

            if (groupA == -1 && groupB == -1) {
                set<char> newSet = {a, b};
                groups.push_back(newSet);
            } else if (groupA != -1 && groupB == -1) {
                groups[groupA].insert(b);
            } else if (groupA == -1 && groupB != -1) {
                groups[groupB].insert(a);
            } else if (groupA != groupB) {
                groups[groupA].insert(groups[groupB].begin(), groups[groupB].end());
                groups.erase(groups.begin() + groupB);
            }
        }

        unordered_map<char, char> mp;
        for (auto& group : groups) {
            char smallest = *group.begin();
            for (char c : group) {
                if (smallest > c) smallest = c;
            }
            for (char c : group) {
                mp[c] = smallest;
            }
        }

        // Step 3: Build result using mapped characters
        string ans = "";
        for (char c : baseStr) {
            if (mp.count(c)) ans += mp[c];
            else ans += c;
        }

        return ans;
    }
};
