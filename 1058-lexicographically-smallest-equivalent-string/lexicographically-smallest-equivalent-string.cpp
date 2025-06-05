class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> groups;

        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            int g1 = -1, g2 = -1;

            // Find group for a and b
            for (int j = 0; j < groups.size(); ++j) {
                if (groups[j].count(a)) g1 = j;
                if (groups[j].count(b)) g2 = j;
            }

            if (g1 == -1 && g2 == -1) {
                groups.push_back({a, b});
            } else if (g1 != -1 && g2 == -1) {
                groups[g1].insert(b);
            } else if (g1 == -1 && g2 != -1) {
                groups[g2].insert(a);
            } else if (g1 != g2) {
                // Merge g2 into g1 and erase g2
                groups[g1].insert(groups[g2].begin(), groups[g2].end());
                groups.erase(groups.begin() + g2);
            }
        }

        // Build map from each character to its smallest in the group
        unordered_map<char, char> smallest;
        for (auto& group : groups) {
            char minChar = *group.begin();
            for (char c : group)
                if (c < minChar) minChar = c;
            for (char c : group)
                smallest[c] = minChar;
        }

        string res = "";
        for (char c : baseStr) {
            res += (smallest.count(c) ? smallest[c] : c);
        }

        return res;
    }
};
